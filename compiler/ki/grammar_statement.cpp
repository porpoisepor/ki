/**
 * Ki <ki/grammar_statement.cpp>
 * 
 * Copyright Agust�n Berg�, Fusion Fenix 2013
 * 
 * Distributed under the Boost Software License, Version 1.0. (See accompanying
 * file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 * 
 * Ki home page: http://github.com/K-ballo/ki
 */

#include "grammar.hpp"

#include <boost/spirit/include/qi_nonterminal.hpp>
#include <boost/spirit/include/qi_operator.hpp>

namespace ki {
    
    void grammar::build_statement_rules( lexer const& lexer )
    {
        statement =
            expression_statement
          | compound_statement
          | return_statement
          | declaration_statement
          | lexer( ";" )
            ;
        BOOST_SPIRIT_DEBUG_NODES((statement));
        
        expression_statement =
            expression >> lexer( ";" )
            ;
        BOOST_SPIRIT_DEBUG_NODES((expression_statement));
        
        compound_statement =
            lexer( "{" ) > *statement > lexer( "}" )
            ;
        BOOST_SPIRIT_DEBUG_NODES((compound_statement));
        
        return_statement =
            lexer( "return" ) > -expression > lexer( ";" )
            ;
        BOOST_SPIRIT_DEBUG_NODES((compound_statement));

        declaration_statement =
            declaration.alias()
            ;
        BOOST_SPIRIT_DEBUG_NODES((declaration_statement));
    }

} // namespace ki
