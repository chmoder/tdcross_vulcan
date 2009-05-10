term.h:

class Term
{
    private:
        int exp;
        int cof;
        char var;
        Term ( const Term & );
        Term & operator = (const Term & );
    public:
        Term ( void )
            :exp(1), cof(0), var('x') {;;;}
        bool Term::operator< ( const Term &term )
        {
            return ( this.exp < term.exp ) ;
        }
        bool Term::operator> ( const Term & )
        {
            return ( this.exp > term.exp ) ;
        }
        bool Term::operator== ( const Term & )
        {
            return ( this.exp == term.exp );
        }
};
