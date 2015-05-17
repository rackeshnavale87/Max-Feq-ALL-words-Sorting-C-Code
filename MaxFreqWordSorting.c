#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 2048
char buf[MAX];

struct word {
	char word[100];
	int count;
	struct word *next;
}word;

struct word *a= NULL, *b=NULL, *temps = NULL,*root = NULL;

struct word *selectionsort(struct word *set, int n)
{
	int i=0, f=0, max=0, j=0;
	temps = (struct word *)malloc(1*sizeof(struct word));
	a=root;
	b=a;
	for (i = 0; i < (n); i++)
	{	
		b=a;
		for (j = i; j <= n; j++)
		{
			if (b->count > a->count)
			{
				strcpy(temps->word,a->word);
				temps->count = a->count;
				strcpy(a->word,b->word);
				a->count = b->count;
				strcpy(b->word,temps->word);
				b->count = temps->count;
			}
			if(j<(n))
				b = b->next;
		}
		if(i<(n-1))
		{a=a->next;}
     	}
	/*printf("\nSORTED List of all %d Unique words & Count\n Count : Word\n-------------------------------------------\n",n);
	temps=root;
	for(f=0;f<=n;f++) 
	{
		printf("%3d : %s\n",temps->count,temps->word);
		temps=temps->next;
	}*/
return root;
}



int main(int argc, char* argv[]) {
	char *p1, temp1[100];
	int lines=0,j=0,f=0,twords=0,Dword=0,flag=1,rootf=0;;
	FILE *fp;
	struct word *temp,*t1;
	fp = fopen("doc.txt","r");
	while (1) {
	        if (fgets(buf, sizeof(buf), fp) == NULL) {			
				fclose(fp);
				break;
		}
		else { 
			lines++;
			p1 = buf;
			char *p1 = buf;
			int z =0;
			while(buf[z]){
				t1=root;flag=1;
				while(*p1 == ' ' || *p1== '.' || *p1== ';' || *p1== ':' || *p1 == '"' || *p1 =='['|| *p1 ==']'|| *p1 ==','|| *p1 =='('|| *p1 ==')'|| *p1 =='!'|| *p1 =='?'|| *p1 =='\''|| *p1 =='-' || *p1=='\n'||*p1=='\t'||*p1=='/'||*p1=='\\' || (*p1=='\0') && buf[z] )
				{
					p1++;z++;
				}
			
				while(!(*p1 == ' ' || *p1== '.' || *p1== ';' || *p1== ':' || *p1 == '"' || *p1 =='['|| *p1 ==']'|| *p1 ==','|| *p1 =='('|| *p1 ==')'|| *p1 =='!'|| *p1 =='?'|| *p1 =='\''|| *p1 =='-' || *p1=='\n'|| *p1=='/'||*p1=='\\') && (*p1!='\0') && (*p1!='\t') && (*p1!='\n'))
				{
					temp1[j] = *p1;
					j++;p1++;z++;
				}
				temp1[j]='\0';
				if(!buf[z]) 
					break;
				j=0;rootf=1;
				temp = (struct word *)malloc(1*sizeof(struct word));
				temp->next = NULL;
				temp->count =1;twords++;
				strcpy(temp->word,temp1);
				if(root==NULL || strcmp(root->word,temp1)==0)
				{
					if(root==NULL)
					{
						root = (struct word *)malloc(1*sizeof(struct word));
						root->next=NULL;
						root=temp;   
						Dword++;
						rootf=0;
					}

					if(strcmp(root->word,temp1)==0 && rootf)
					{
						root->count++;
						free(temp);
					}
				}
				else 
				{
					t1=root;
					while((t1->next!=NULL) && flag) 
					{
						if(strcmp(t1->word,temp1)==0) 
						{
							t1->count++;
							free(temp);
							
							flag=0;
						}
						t1=t1->next;
						
					}
					if(flag) 
					{
						if(strcmp(t1->word,temp1)==0) 
						{
							t1->count++;
							free(temp);
						}
						else
						{
							t1->next = temp;Dword++; 
							flag =1;
						}
					}
				}
			}
		}
	}
//------------------------------------------------------------------------------------------------------
	if(Dword>1)
	root = selectionsort(root,Dword-1);
//------------------------------------------------------------------------------------------------------
	printf("\nList of all %d Unique words with their count\n Count : Word\n",Dword);
	printf("-------------------------------------------\n");
	t1=root;
	for(f=0;f<Dword;f++) {
		printf("%3d : %s\n",t1->count,t1->word);
		t1=t1->next;
	}

//------------------------------------------------------------------------------------------------------
		t1=root;
		struct word *max = (struct word *)malloc(1*sizeof(struct word));
		int MaxC = 0;
		for(f=0;f<Dword;f++) {
			if(MaxC < t1->count) {
				max->count = t1->count;
				strcpy(max->word,t1->word);
				MaxC = t1->count;
			}
			t1=t1->next;
		}
	printf("\nMaximum frequently used word");
	printf("\n-------------------------------------------\n");
	printf("%3d : %s\n",max->count,max->word);
	printf("-------------------------------------------\n");
//------------------------------------------------------------------------------------------------------
free(a);free(b);free(temps);
return 0;
}
