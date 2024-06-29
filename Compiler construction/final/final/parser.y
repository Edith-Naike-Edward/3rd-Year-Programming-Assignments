%{
    #include<stdio.h>
    #include<string.h>
    #include<stdlib.h>
    #include<ctype.h>
    #include"lex.yy.c"
    
    void yyerror(const char *s);
    int yylex();
    int yywrap();

    void add(char c, char *str);
    void printTree(struct node*, int depth, int branch[]);
    void printBranches(int branch[], int depth);
    
    struct node* mknode(struct node *one, struct node *two, struct node *three, struct node *four, struct node *five, char *token);

    struct dataType {
        char * id_name;
        char * data_type;
        char * type;
        int line_no;
    } symbol_table[200];

    int count=0;
    int q;
    char type[10];
    extern int countn;

    struct node *head;
    struct node {
        struct node *one;
        struct node *two;
        struct node *three;
        struct node *four;
        struct node *five;
        char *token;
    };
%}

%union { 
	struct var_name { 
		char name[100]; 
		struct node* nd;
	} nd_obj; 
} 


%token <nd_obj> PRINTF VOID IF ELSE INT WHILE FLOAT RETURN NUMBER MAIN FLOAT_NUM ID STRING LE ASSIGN GE EQ NE GT LT AND OR NOT ADD SUBTRACT DIVIDE MULTIPLY O_BRACK C_BRACK OC_BRACK CC_BRACK S_COLON COMMA
%type <nd_obj> program functionList if_stmt if_else else_if function paramList param mainFunction type compoundStmt localDeclaration varDeclaration statement statementList condition expression additiveExpression relop addop term mulop factor args


/* Grammar Rules */

%%

program: functionList mainFunction {$$.nd = mknode($1.nd, $2.nd, NULL, NULL, NULL, "program"); head = $$.nd;}
;

functionList: functionList function {$$.nd = mknode($1.nd, $2.nd, NULL, NULL, NULL, "functionList");}
| { $$.nd = NULL; }
;

function:type ID { add('V', "ID"); } paramList compoundStmt {$2.nd = mknode(NULL, NULL, NULL, NULL, NULL, "ID"); $$.nd = mknode($1.nd, $2.nd, $4.nd, $5.nd, NULL, "function");}
;

paramList: O_BRACK { add('S', "O_BRACK"); } param  C_BRACK { add('S', "C_BRACK"); } {$1.nd = mknode(NULL, NULL, NULL, NULL, NULL, "O_BRACK"); $4.nd = mknode(NULL, NULL, NULL, NULL, NULL, "C_BRACK"); $$.nd = mknode($1.nd, $3.nd, $4.nd, NULL, NULL, "paramList");}
;

param: param COMMA { add('S', "COMMA"); } param {$2.nd = mknode(NULL, NULL, NULL, NULL, NULL, "COMMA"); $$.nd = mknode($1.nd, $2.nd, $4.nd, NULL, NULL, "param");}
| param {$$.nd = mknode($1.nd, NULL, NULL, NULL, NULL, "param");}
| type ID { add('V', "ID"); } {$2.nd = mknode(NULL, NULL, NULL, NULL, NULL, "ID"); $$.nd = mknode($1.nd, $2.nd, NULL, NULL, NULL, "param");}
| { $$.nd = NULL; }
;

mainFunction: INT { add('K', "INT"); } MAIN { add('K', "MAIN"); } O_BRACK { add('S', "O_BRACK"); } C_BRACK { add('S', "C_BRACK"); } compoundStmt {$1.nd = mknode(NULL, NULL, NULL, NULL, NULL, "INT"); $3.nd = mknode(NULL, NULL, NULL, NULL, NULL, "MAIN"); $5.nd = mknode(NULL, NULL, NULL, NULL, NULL, "O_BRACK"); $7.nd = mknode(NULL, NULL, NULL, NULL, NULL, "C_BRACK"); $$.nd = mknode($1.nd, $3.nd, $5.nd, $7.nd, $9.nd, "main");;}
;


type: INT { add('K', "INT"); } {$1.nd = mknode(NULL, NULL, NULL, NULL, NULL, "INT"); $$.nd = mknode($1.nd, NULL, NULL, NULL, NULL, "type");}
| FLOAT { add('K', "FLOAT"); } {$1.nd = mknode(NULL, NULL, NULL, NULL, NULL, "FLOAT"); $$.nd = mknode($1.nd, NULL, NULL, NULL, NULL, "type");}
| VOID { add('K', "VOID"); } {$1.nd = mknode(NULL, NULL, NULL, NULL, NULL, "VOID"); $$.nd = mknode($1.nd, NULL, NULL, NULL, NULL, "type");}
;

compoundStmt: OC_BRACK { add('S', "OC_BRACK"); } localDeclaration statementList CC_BRACK { add('S', "CC_BRACK"); }{$1.nd = mknode(NULL, NULL, NULL, NULL, NULL, "OC_BRACK"); $5.nd = mknode(NULL, NULL, NULL, NULL, NULL, "CC_BRACK"); $$.nd = mknode($1.nd, $3.nd, $4.nd, $5.nd, NULL, "compStmt");}
;

localDeclaration: varDeclaration COMMA { add('S', "COMMA"); } localDeclaration {$2.nd = mknode(NULL, NULL, NULL, NULL, NULL, "COMMA"); $$.nd = mknode($1.nd, $2.nd, $4.nd, NULL, NULL, "Declarations");}
| varDeclaration S_COLON { add('S', "S_COLON"); } localDeclaration {$2.nd = mknode(NULL, NULL, NULL, NULL, NULL, "S_COLON"); $$.nd = mknode($1.nd, $2.nd, $4.nd, NULL, NULL, "Declarations");}
| varDeclaration S_COLON { add('S', "S_COLON"); } {$2.nd = mknode(NULL, NULL, NULL, NULL, NULL, "S_COLON"); $$.nd = mknode($1.nd, $2.nd, NULL, NULL, NULL, "Declarations");}
| { $$.nd = NULL; }
;

varDeclaration: type ID { add('V', "ID"); } ASSIGN { add('O', "ASSIGN"); } expression {$2.nd = mknode(NULL, NULL, NULL, NULL, NULL, "ID"); $4.nd = mknode(NULL, NULL, NULL, NULL, NULL, "ASSIGN"); $$.nd = mknode($1.nd, $2.nd, $4.nd, $6.nd, NULL, "var");}
;

statementList: statement statementList {$$.nd = mknode($1.nd, $2.nd, NULL, NULL, NULL, "stmtList");}
| statement {$$.nd = mknode($1.nd, NULL, NULL, NULL, NULL, "stmtList");}
;

statement: expression {$$.nd = mknode($1.nd, NULL, NULL, NULL, NULL, "stmt");}
| if_stmt {$$.nd = mknode($1.nd, NULL, NULL, NULL, NULL, "stmt");}
| if_stmt if_else {$$.nd = mknode($1.nd, $2.nd, NULL, NULL, NULL, "stmt");}
| if_stmt else_if if_else {$$.nd = mknode($1.nd, $2.nd, $3.nd, NULL, NULL, "stmt");}
| WHILE { add('K', "WHILE"); } condition compoundStmt {$$.nd = mknode($3.nd, $4.nd, NULL, NULL, NULL, "while_stmt");}
| RETURN { add('K', "RETURN"); } expression S_COLON { add('S', "S_COLON"); } {$1.nd = mknode(NULL, NULL, NULL, NULL, NULL, "RETURN"); $4.nd = mknode(NULL, NULL, NULL, NULL, NULL, "S_COLON"); $$.nd = mknode($1.nd, $3.nd, $4.nd, NULL, NULL, "stmt");}
| PRINTF { add('K', "PRINTF"); } O_BRACK { add('S', "O_BRACK"); } STRING { add('C', "STRING"); } COMMA { add('S', "COMMA"); } expression C_BRACK { add('S', "C_BRACK"); } S_COLON { add('S', "S_COLON"); } {$1.nd = mknode(NULL, NULL, NULL, NULL, NULL, "PRINTF"); $3.nd = mknode(NULL, NULL, NULL, NULL, NULL, "O_BRACK"); $5.nd = mknode(NULL, NULL, NULL, NULL, NULL, "STRING"); $10.nd = mknode(NULL, NULL, NULL, NULL, NULL, "C_BRACK"); $12.nd = mknode(NULL, NULL, NULL, NULL, NULL, "S_COLON"); $7.nd = mknode($9.nd, $10.nd, $12.nd, NULL, NULL, "COMMA"); $$.nd = mknode($1.nd, $3.nd, $5.nd, $7.nd, NULL, "stmt");}
| PRINTF { add('K', "PRINTF"); } O_BRACK { add('S', "O_BRACK"); } STRING { add('C', "STRING"); } C_BRACK { add('S', "C_BRACK"); } S_COLON { add('S', "S_COLON"); } {$1.nd = mknode(NULL, NULL, NULL, NULL, NULL, "PRINTF"); $3.nd = mknode(NULL, NULL, NULL, NULL, NULL, "O_BRACK"); $5.nd = mknode(NULL, NULL, NULL, NULL, NULL, "STRING"); $7.nd = mknode(NULL, NULL, NULL, NULL, NULL, "C_BRACK"); $9.nd = mknode(NULL, NULL, NULL, NULL, NULL, "S_COLON"); $$.nd = mknode($1.nd, $3.nd, $5.nd, $7.nd, $9.nd, "stmt");}
;

if_stmt: IF { add('K', "IF"); } condition compoundStmt {$1.nd = mknode(NULL, NULL, NULL, NULL, NULL, "IF"); $$.nd = mknode($1.nd, $3.nd, $4.nd, NULL, NULL, "if_stmt");}
;

if_else: ELSE { add('K', "ELSE"); } compoundStmt {$1.nd = mknode(NULL, NULL, NULL, NULL, NULL, "ELSE"); $$.nd = mknode($1.nd, $3.nd, NULL, NULL, NULL, "if_stmt");}
;

else_if: ELSE { add('K', "ELSE"); } IF { add('K', "IF"); } condition compoundStmt {$1.nd = mknode(NULL, NULL, NULL, NULL, NULL, "ELSE"); $3.nd = mknode(NULL, NULL, NULL, NULL, NULL, "IF"); $$.nd = mknode($1.nd, $3.nd, $5.nd, $6.nd, NULL, "if_stmt");}
;

condition: O_BRACK { add('S', "O_BRACK"); } expression C_BRACK { add('S', "C_BRACK"); } {$1.nd = mknode(NULL, NULL, NULL, NULL, NULL, "O_BRACK"); $4.nd = mknode(NULL, NULL, NULL, NULL, NULL, "C_BRACK"); $$.nd = mknode($1.nd, $3.nd, $4.nd, NULL, NULL, "condition");}
;

expression: additiveExpression relop expression {$$.nd = mknode($1.nd, $2.nd, $3.nd, NULL, NULL, "expr");}
| additiveExpression {$$.nd = mknode($1.nd, NULL, NULL, NULL, NULL, "expr");}
;


additiveExpression: additiveExpression addop term {$$.nd = mknode($1.nd, $2.nd, $3.nd, NULL, NULL, "addExp");}
| term {$$.nd = mknode($1.nd, NULL, NULL, NULL, NULL, "addExp");}
;

relop: LE { add('O', "LE"); } {$1.nd = mknode(NULL, NULL, NULL, NULL, NULL, "LE"); $$.nd = mknode($1.nd, NULL, NULL, NULL, NULL, "relop");}
| GE { add('O', "GE"); } {$1.nd = mknode(NULL, NULL, NULL, NULL, NULL, "GE"); $$.nd = mknode($1.nd, NULL, NULL, NULL, NULL, "relop");}
| EQ { add('O', "EQ"); } {$1.nd = mknode(NULL, NULL, NULL, NULL, NULL, "EQ"); $$.nd = mknode($1.nd, NULL, NULL, NULL, NULL, "relop");}
| NE { add('O', "NE"); } {$1.nd = mknode(NULL, NULL, NULL, NULL, NULL, "NE"); $$.nd = mknode($1.nd, NULL, NULL, NULL, NULL, "relop");}
| GT { add('O', "GT"); } {$1.nd = mknode(NULL, NULL, NULL, NULL, NULL, "GT"); $$.nd = mknode($1.nd, NULL, NULL, NULL, NULL, "relop");}
| LT { add('O', "LT"); } {$1.nd = mknode(NULL, NULL, NULL, NULL, NULL, "LT"); $$.nd = mknode($1.nd, NULL, NULL, NULL, NULL, "relop");}
| AND { add('O', "AND"); } {$1.nd = mknode(NULL, NULL, NULL, NULL, NULL, "AND"); $$.nd = mknode($1.nd, NULL, NULL, NULL, NULL, "relop");}
| OR { add('O', "OR"); } {$1.nd = mknode(NULL, NULL, NULL, NULL, NULL, "OR"); $$.nd = mknode($1.nd, NULL, NULL, NULL, NULL, "relop");}
| NOT { add('O', "NOT"); } {$1.nd = mknode(NULL, NULL, NULL, NULL, NULL, "NOT"); $$.nd = mknode($1.nd, NULL, NULL, NULL, NULL, "relop");}
;

term: term mulop factor {$$.nd = mknode($1.nd, $2.nd, $3.nd, NULL, NULL, "term");}
| factor {$$.nd = mknode($1.nd, NULL, NULL, NULL, NULL, "term");}
;

addop: ADD { add('O', "ADD"); } {$1.nd = mknode(NULL, NULL, NULL, NULL, NULL, "ADD"); $$.nd = mknode($1.nd, NULL, NULL, NULL, NULL, "addop");}
| SUBTRACT { add('O', "SUBTRACT"); } {$1.nd = mknode(NULL, NULL, NULL, NULL, NULL, "SUBTRACT"); $$.nd = mknode($1.nd, NULL, NULL, NULL, NULL, "addop");}
;

mulop: MULTIPLY { add('O', "MULTIPLY"); } {$1.nd = mknode(NULL, NULL, NULL, NULL, NULL, "MULTIPLY"); $$.nd = mknode($1.nd, NULL, NULL, NULL, NULL, "mulop");}
| DIVIDE { add('O', "DIVIDE"); } {$1.nd = mknode(NULL, NULL, NULL, NULL, NULL, "DIVIDE"); $$.nd = mknode($1.nd, NULL, NULL, NULL, NULL, "mulop");}
;

factor: O_BRACK { add('S', "O_BRACK"); } expression C_BRACK { add('S', "C_BRACK"); } {$1.nd = mknode(NULL, NULL, NULL, NULL, NULL, "O_BRACK"); $4.nd = mknode(NULL, NULL, NULL, NULL, NULL, "C_BRACK"); $$.nd = mknode($1.nd, $3.nd, $4.nd, NULL, NULL, "factor");}
| ID { add('V', "ID"); } O_BRACK { add('S', "O_BRACK"); } args C_BRACK { add('S', "C_BRACK"); } {$1.nd = mknode(NULL, NULL, NULL, NULL, NULL, "ID"); $3.nd = mknode(NULL, NULL, NULL, NULL, NULL, "O_BRACK"); $6.nd = mknode(NULL, NULL, NULL, NULL, NULL, "C_BRACK"); $$.nd = mknode($1.nd, $3.nd, $5.nd, $6.nd, NULL, "funCall");}
| ID { add('V', "ID"); } {$1.nd = mknode(NULL, NULL, NULL, NULL, NULL, "ID"); $$.nd = mknode($1.nd, NULL, NULL, NULL, NULL, "factor");}
| NUMBER { add('C', "NUMBER"); } {$1.nd = mknode(NULL, NULL, NULL, NULL, NULL, "NUMBER"); $$.nd = mknode($1.nd, NULL, NULL, NULL, NULL, "factor");}
| FLOAT_NUM { add('C', "FLOAT_NUM"); } {$1.nd = mknode(NULL, NULL, NULL, NULL, NULL, "FLOAT_NUM"); $$.nd = mknode($1.nd, NULL, NULL, NULL, NULL, "factor");}
;

args: args COMMA { add('S', "COMMA"); } args {$2.nd = mknode(NULL, NULL, NULL, NULL, NULL, "COMMA"); $$.nd = mknode($1.nd, $2.nd, $4.nd, NULL, NULL, "args");}
| args {$$.nd = mknode($1.nd, NULL, NULL, NULL, NULL, "args");}
| ID { add('V', "ID"); } {$1.nd = mknode(NULL, NULL, NULL, NULL, NULL, "ID"); $$.nd = mknode($1.nd, NULL, NULL, NULL, NULL, "args");}
| NUMBER { add('C', "NUMBER"); } {$1.nd = mknode(NULL, NULL, NULL, NULL, NULL, "NUMBER"); $$.nd = mknode($1.nd, NULL, NULL, NULL, NULL, "args");}
| { $$.nd = NULL; } 
;


%%

int main() {
    yyparse();
    printf("\n\n");
    printf("\t\t PHASE 1: LEXICAL ANALYSIS \n\n");
    printf("\nSYMBOL\t\tTYPE\t\tTOKEN\t\tLINE NUMBER \n");
    printf("_______________________________________________________\n\n");
    int i=0;
    for(i=0; i<count; i++) {
        printf("%s\t\t%s\t\t%s\t\t%d\t\n", symbol_table[i].id_name, symbol_table[i].type, symbol_table[i].data_type, symbol_table[i].line_no);
    }
    for(i=0;i<count;i++) {
        free(symbol_table[i].id_name);
        free(symbol_table[i].type);
    }

    printf("\n\n");
    printf("\t\t PHASE 2: SYNTAX ANALYSIS \n\n");
    int branch[100] = {0};

    printTree(head, 0, branch); 
    printf("\n\n");
}

void add(char c, char *str) {
    if(c == 'S') {
            symbol_table[count].id_name=strdup(yytext);
            symbol_table[count].data_type=strdup(str);
            symbol_table[count].line_no=countn;
            symbol_table[count].type=strdup("Symbol");
            count++;
        }
        else if(c == 'K') {
            symbol_table[count].id_name=strdup(yytext);
            symbol_table[count].data_type=strdup(str);
            symbol_table[count].line_no=countn;
            symbol_table[count].type=strdup("Keyword\t");
            count++;
        }
        else if(c == 'V') {
            symbol_table[count].id_name=strdup(yytext);
            symbol_table[count].data_type=strdup(str);
            symbol_table[count].line_no=countn;
            symbol_table[count].type=strdup("Variable");
            count++;
        }
        else if(c == 'C') {
            symbol_table[count].id_name=strdup(yytext);
            symbol_table[count].data_type=strdup(str);
            symbol_table[count].line_no=countn;
            symbol_table[count].type=strdup("Value");
            count++;
        }
        else if(c == 'O') {
            symbol_table[count].id_name=strdup(yytext);
            symbol_table[count].data_type=strdup(str);
            symbol_table[count].line_no=countn;
            symbol_table[count].type=strdup("Operator");
            count++;
        }
	
}

struct node* mknode(struct node *one, struct node *two, struct node *three, struct node *four, struct node *five, char *token) {	
	struct node *newnode = (struct node *)malloc(sizeof(struct node));
	char *newstr = (char *)malloc(strlen(token)+1);
	strcpy(newstr, token);
	newnode->one = one;
	newnode->two = two;
    newnode->three = three;
	newnode->four = four;
    newnode->five = five;
	newnode->token = newstr;
	return(newnode);
}


void printBranches(int branch[], int depth) {
    for (int i = 0; i < depth; ++i) {
        if (i == depth - 1) {
            printf("|-- ");
        } else {
            printf(branch[i] ? "|   " : "    ");
        }
    }
}

void printTree(struct node *root, int depth, int branch[]) {
    if (root == NULL) {
        return;
    }

    printBranches(branch, depth);
    printf("%s\n", root->token);

    // Update the branch array: 1 if sibling nodes exist, 0 otherwise
    branch[depth] = (root->two != NULL || root->three != NULL || root->four != NULL || root->five != NULL);

    printTree(root->one, depth + 1, branch);
    printTree(root->two, depth + 1, branch);
    printTree(root->three, depth + 1, branch);
    printTree(root->four, depth + 1, branch);

    // For the last node, change the branch symbol
    if (root->five != NULL) {
        branch[depth] = 0; // No more siblings
        printBranches(branch, depth);
        printf("| ");
        printTree(root->five, depth + 1, branch);
    }
}

void yyerror(const char* msg) {
    fprintf(stderr, "%s\n", msg);
}

