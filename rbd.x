/* rbd.x  
   especificação rpc para um programa de banco de dados  
   que oferece os procedimentos INSERE, REMOVE e BUSCA 
*/ 
const MAXNAMELEN = 255;
typedef string nametype<MAXNAMELEN>;	
struct Agenda {        /* estrutura não usada, declarada para ilustrar como rpcgen */ 
    nametype nome;      /* constrói rotinas XDR para converter estruturas */ 
    nametype telefone;  
    nametype endereco;  
    nametype email;  
}; 
program RBDPROG{           /* nome do programa remoto */ 
    version RDBVERS{       /* declaração da versão */ 
          int INICIALIZAR(void) = 1;   /* primeiro procedimento deste programa */ 
          int INSERE(struct Agenda) = 2;      /* segundo procedimento deste programa */ 
          int REMOVE(string) = 3;      /* terceiro procedimento deste programa */ 
          Agenda BUSCA(string) = 4;       /* quarto procedimento deste programa */ 
          int NUMERO_AGENDA(void) = 5;       /* quinto procedimento deste programa */ 
          Agenda LISTAR(int) = 6;       /* sexto procedimento deste programa */ 
    } = 1;                /* definição da versão do programa */ 
} = 0x30090950;     /* número do programa remoto (deve ser único) */
