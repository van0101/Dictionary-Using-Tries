#include<stdio.h>

#define MAX 10000
typedef struct trie
{
    int last_word;//is the node the last word of letter or not 1=yes 0=not the last word
    struct trie *child[27];//children of each node=number of alphabets 0-27 = 1-26
    char *meaning;
    //int meaning[100];//meaning

}trie;
trie *head;//points to the first location;
void display_dictionary();
void make_null(trie *arr[27]);
void create()
{
    head=(trie *)malloc(sizeof(trie));
    head->last_word=0;
    head->meaning="!";//(int)33;as 1st node will not be part of a sequence
    make_null(head->child);
}
// int index;
void make_null(trie *arr[27])
{
    int i=0;
    for(i=0;i<27;i++)
    {
        arr[i]=NULL;
    }
}
void initialize_dictionary()
{
    trie *temp=head;
    trie *mov=head;
    char wordx[10][1000]={"arch","archaeology","archaic","archaism","archangel","formal","formaldehyde","formalin","formalism","format"};
    char wordm[10][1000]={"a curved structure supporting a bridge","Study of ancient history","Belonging to former or ancient times","an old fashion word or phrase","an angel of high rank","officially recognized","a gas used in solution as a preservative and disinfectant","a solution of formaldehyde and water","excessive concern with rules and outward form","the way something is arranged"};

    int ind;
    int i;
    int j=0;
    for(j=0;j<10;j++)
    {
     for(i=0;i<strlen(wordx[j]);i++)
    {
        ind=(int)wordx[j][i]-97+1;
         if(temp->child[ind]==NULL)//insert a new node if not traversed else go on the path
         {

            trie *ptr=(trie *)malloc(sizeof(trie));
            make_null(ptr->child);
            temp->child[ind]=ptr;
            temp=ptr;

                if(i==strlen(wordx[j])-1)
                {
                    ptr->last_word=1;
                    ptr->meaning=wordm[j];
                }
                else
                {
                    ptr->last_word=0;
                    ptr->meaning="!";
                }
         }
         else
         {
              temp=temp->child[ind];
         }
    }
    temp=head;
    }

}
void display_dictionary(char search[100])
{
    trie *temp=head;
    trie *move=head;

    //char search[100]="archaism";
    int ind,i,j,exit_flag=0;

    for(i=0;i<strlen(search);i++)
    {
        ind=(int)search[i]-97+1;
        move=temp->child[ind];

        if(move==NULL)
        {
            exit_flag=1;
            printf("WORD NOT FOUND \n");
            break;
        }
        temp=move;
    }
    if(exit_flag==0)
        printf("Meaning: %s\n",move->meaning);
}
void menu()
{
    char wordx[10][1000]={"arch","archaeology","archaic","archaism","archangel","formal","formaldehyde","formalin","formalism","format"};
    int i,j;

    for(i=0;i<9;i=i+2)
    {
        printf("%d)%.*s  \t %d)%.*s\n",i+1,15,wordx[i],i+2,15,wordx[i+1]);
    }

    printf("\n\n\n");
    printf("Enter the number corresponding to the word to show meaning\n");
    int ch;
    //scanf("%d",&ch);
    ch = 1;
    switch(ch)
    {
    case 1:
        display_dictionary(wordx[ch-1]);
        break;
    case 2:
        display_dictionary(wordx[ch-1]);break;
    case 3:
        display_dictionary(wordx[ch-1]);break;
    case 4:
        display_dictionary(wordx[ch-1]);break;
    case 5:
        display_dictionary(wordx[ch-1]);break;
    case 6:
        display_dictionary(wordx[ch-1]);break;
    case 7:
        display_dictionary(wordx[ch-1]);break;
    case 8:
        display_dictionary(wordx[ch-1]);break;
    case 9:
        display_dictionary(wordx[ch-1]);break;
    case 10:
        display_dictionary(wordx[ch-1]);break;
    default:
        {
            printf("Wrong Choice!\n");
            exit(1);

        }

    }
}
int main()
{
    create();
   // printf("trie created\n");
    initialize_dictionary();
    //printf("dictionary initialized\n");

     menu();
    //display_dictionary();
   // printf("displayed\n");
}
