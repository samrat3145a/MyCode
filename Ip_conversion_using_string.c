#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
 int decimal_to_binary(int sum)
 {
     if(sum>255 || sum<0)
     {
         printf("Invalid IP address!!");
         exit(1);
     }

     int r;
    int arr[8];

    int i,n=0;
    for(i=0;i<8;i++)
        arr[i]=0;
     while(sum>0)
     {
         r=sum%2;
         arr[n]=r;
         sum=sum/2;
         n=n+1;
         //printf("\n\t%d %d %d\t\n",r,arr[n],n);
     }
     for(i=7;i>=0;i--){
        printf("%d",arr[i]);
        arr[i]=0;
     }

 }
int binary_to_decimal(int sum)
 {  int r,res=0,arr[100],i=0,n=0;
    //printf("\n\t\t%d\n",sum);
     while(sum>0)
     {
         r=sum%10;
         res=res+pow(2,i)*r;

         sum=sum/10;
         i++;
         //printf("\n\t%d %d %d\t\n",res,arr[n],n);
     }
     if(res>255 || res<0)
     {
         printf("Invalid IP address!!");
         exit(1);
     }
     printf("%d",res);

 }


int main()
{   int n,ip[100];
    while(1){
        printf("\nWELCOME TO MENU!!\nEnter your choice:\n");
        printf("\n1.Decimal to Binary!");
        printf("\n2.Binary to Decimal!");
        printf("\n3.Exit!!\n");
        scanf("%d",&n);

        switch(n){

            case 1:printf("Enter the IP address in dotted decimal format:");
                    int num=0,i,sum=0;
                    char ip1[100];
                    scanf("%s",&ip1);
                    printf("IP address in binary format:");
                    for(i=0;i<=strlen(ip1);i++)
                    {
                        if(i==strlen(ip1))
                        {
                            decimal_to_binary(sum);
                            sum=0;
                            break;
                        }
                        else if(ip1[i]=='.' && i< strlen(ip1) )
                        {   //printf("\n\t%d\t\n",strlen(ip1));
                            decimal_to_binary(sum);
                            printf(".");
                            sum=0;
                        }

                        else{
                            int symbol=ip1[i]-48;
                            sum=sum*10+symbol;
                        }
                    }
                    printf("\n\n");
                    break;

            case 2: printf("Enter the IP address in binary format:");
                    i,sum=0;
                    char ip2[100];
                    scanf("%s",&ip2);
                    printf("IP address in binary format:");
                    for(i=0;i<=strlen(ip2);i++)
                    {
                        if(i==strlen(ip2))
                        {
                            binary_to_decimal(sum);
                            sum=0;
                            break;
                        }
                        else if(ip2[i]=='.' && i< strlen(ip2) )
                        {
                            binary_to_decimal(sum);
                            printf(".");
                            sum=0;
                        }

                        else{
                            int symbol=ip2[i]-48;
                            sum=sum*10+symbol;
                        }
                    }
                    printf("\n\n");
                    break;
            case 3:printf("EXIT");
                    exit(1);
            default:printf("You have Entered a wrong choice:");
                    break;

        }




    }







}
