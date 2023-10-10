#include <bits/stdc++.h> 
void sort012(int *arr, int n)
{
   int c1=0;
   int c2=0;
   int c0=0;
   for(int i=0;i<n;i++){
      if(arr[i]==0){
         c0+=1;

      }
      else if(arr[i]==1){
         c1+=1;
      }
      else{
         c2+=1;
      }

   }
   c1=c0+c1;
   c2=c2+c1;

   for(int i=0;i<n;i++){
      if(i<c0){
         arr[i]=0;;
      }else if(i<c1){
         arr[i]=1;
      }else{
         arr[i]=2;
      }
   }
  
}