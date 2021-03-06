/*
 * Copyright (C) 2008 Emweb bvba, Kessel-Lo, Belgium.
 *
 * See the LICENSE file for terms of use.
 */

#include "Wt/Dbo/SqlStatement"

namespace Wt {
  namespace Dbo {

SqlStatement::SqlStatement()
  : inuse_(false)
{ }

SqlStatement::~SqlStatement()
{ }

bool SqlStatement::use()
{
  if (!inuse_) {
    inuse_ = true;
    return true;
  } else
    return false;
}

void SqlStatement::done()
{
  reset();
  inuse_ = false;
}

ScopedStatementUse::ScopedStatementUse(SqlStatement *statement)
  : s_(statement)
{ }

void ScopedStatementUse::operator()(SqlStatement *statement)
{
  s_ = statement;
}

ScopedStatementUse::~ScopedStatementUse()
{
  if (s_)
    s_->done();
}

  }
}
