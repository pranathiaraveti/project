#include <stdio.h>
#include <stdlib.h>
#include<string.h>
void display();
void createnode();
void insertend();
void deleteNode();
struct oldSongsNode
{
  char songName[100];
  char songTime[6];
  struct oldSongsNode *prev;
  struct oldSongsNode *next;
}*head=NULL,*temp=NULL;

void createnode(char* name,char *mins)
{
    temp=(struct oldSongsNode*)malloc(sizeof(struct oldSongsNode));
    strcpy(temp->songName,name);
    strcpy(temp->songTime,mins);
    temp->next=NULL;
    temp->prev=NULL;
    insertend();
}
void insertend()
{
  
  struct oldSongsNode *temp2=NULL;
  if(head==NULL)
  {
   head=temp;
   temp=NULL;
  }
  else{
      temp2=head;
      while(temp2->next!=NULL)
          temp2=temp2->next;
      temp2->next=temp;
      temp->prev=temp2;
      
  }
  
   
}
void deleteNode(struct oldSongsNode *temp3){
    if(head==temp3 && temp3->next!=NULL)
{
        head=temp3->next;
        temp3->next->prev=NULL;
temp3->next=NULL;
}
    else if(temp3->prev!=NULL && temp3->next!=NULL){
        temp3->prev->next=temp3->next;
        temp3->next->prev=temp3->prev;
        temp3->next=NULL;
        temp3->prev=NULL;
    }
else if(temp3->next==NULL)
{
temp3->prev->next=NULL;
temp3->prev=NULL;
}	

    
}
void display()
{
    if(head==NULL)
    {
     printf("List is empty");
    }
    else
    {
        temp=head;
        while(temp!=NULL)
        {
            printf("Song Name:%s\t\t Song Time:%s\n",temp->songName,temp->songTime);
            temp=temp->next;
        }
    } 
}

int main()
{
    int choice,songChoice;
char deleteConfirmation;
    char name[100];
    char mins[6];
    struct oldSongsNode *temp3=NULL;
    
        createnode("abc","3:40");
        createnode("xyz","2:40");
        createnode("pqr","3:40");
        choices:
        printf("The Songs Present in the list are:\n");
        display();
        
        printf("\n1. Add the song to the list");
        printf("\n2. Play the song\n");
        scanf("%d",&choice);
        if(choice==1)
        {
            printf("\nEnter Song Name:");
            scanf("%s",name);
            printf("\nEnter Song Time:");
            scanf("%s",mins);
            createnode(name,mins);
            goto choices;
        }
        else if(choice==2)
        {
            temp3=head;
            printf("Playing the song %s and song time is %s\n",temp3->songName,temp3->songTime);
            do
            {
                printf("1. Play prev song\n");
                printf("2. Play next song\n");
                printf("3. Stop the playing song\n");
                printf("4. Start the stopped song\n");
                printf("5. Delete the current song\n");
                printf("6. Goto Home\n");
                printf("7. To exit the Media player\n");
                scanf("%d",&songChoice);
                switch(songChoice)
                {
                    case 1: 
                   
                        if(temp3->prev!=NULL)
                        {
                            temp3=temp3->prev;
                            printf("Playing the song %s and song time is %s\n",temp3->songName,temp3->songTime);
                        }
                        else
                            printf("%s is the first song..Play next song\n",temp3->songName);
                        break;
                    case 2:
                    
                        if(temp3->next!=NULL)
                        {
                            temp3=temp3->next;
                            printf("Playing the song %s and song time is %s\n",temp3->songName,temp3->songTime);
                        }
                        else
                            printf("%s is the last song..play prev song\n",temp3->songName);
                        break;
                    case 3:
                        printf("Stopped playing the song %s and song time is %s\n",temp3->songName,temp3->songTime);
                        break;
                    case 4:
                        printf("Started playing the song %s and song time is %s\n",temp3->songName,temp3->songTime);
                        break;
                    case 5:
                        printf("Do you want to delete the song %s??(y/n) : ",temp3->songName);
                        scanf("\n%c",&deleteConfirmation);
                        if(deleteConfirmation=='y')
                            deleteNode(temp3);
                        else
                            break;
printf("current song deleted successfully\n");
goto choices;
                    case 6:
                        goto choices;
                        break;
                    default:
                        break;
                }
           
                
            
            }while(songChoice<=6);
            if(songChoice>=6)
            printf("Thank you for using this player..");
            exit(0);
            
        }
        else{
            printf("Please enter correct choice..\n");
            goto choices;
        }
    return 0;
}
