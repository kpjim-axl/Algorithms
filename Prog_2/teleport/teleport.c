#include <stdio.h>
#include <stdlib.h>
int partition(int **,int,int);
void q_sort(int **,int,int);
int lis(int *,int);
int binary(int *,int,int);

int partition(int **array,int left,int right){
  int pivot=array[left][0];int key=array[left][1];int i=left-1;int j=right+1;int *temp;
  while(1){
    while ((array[++i][0] < pivot) || ((array[i][0]==pivot)&&(array[i][1]<key)));	//ta3inomise prwta ta arr[i][0] kai an
    while ((array[--j][0] > pivot) || ((array[j][0]==pivot)&&(array[j][1]>key)));	//arr[i][0]==arr[j][0] ta3inomise kai
    if (i<j){										//ta arr[i][1],arr[j][1]
      temp=array[i];
      array[i]=array[j];
      array[j]=temp;
    }
    else return (j);
  }
}

void q_sort(int **array,int left,int right){						//bl partition
  int i;
  if (left >= right) return;
  i = partition(array,left,right);
  q_sort(array,left,i);
  q_sort(array,i+1,right);
}

int binary(int *max,int size,int a){			//llis
  int high = size - 1;
  int low = 0;
  int piv=(high+low)/2;
  while (high-low>1){
    if (a < max[piv])
      high=piv;
    else 
      low=piv;
    piv=(high+low)/2;
  }
  if (max[low]>a)
    max[low]=a;
  else if (max[high]>a)
    max[high]=a;
  else max[size++]=a;
  return size;
}

int lis(int *list,int l_size){				//longest increasing subsequence --> O(nlogn)
  int *buf;
  int i,b_size=1;
  buf=malloc(l_size*sizeof(int));
  for(i=0;i<l_size;i++)
    buf[i]=0;
  for(i=0;i<l_size;i++)
    b_size=binary(buf,b_size,list[i]);
  free(buf);
  return b_size-1;
}

int main(void){
  int N;
  int **ft;
  int *list;
  int i;
  scanf("%d",&N);
  ft=malloc(N*sizeof(int *));
  list=malloc(N*sizeof(int));
  for (i=0;i<N;i++){
    ft[i]=malloc(2*sizeof(int));
    scanf("%d %d",&ft[i][0],&ft[i][1]);
  }
  q_sort(ft,0,N-1);
  for (i=0;i<N;i++){
    list[i]=ft[i][1];
  }
  printf("%d\n",lis(list,N));
  return 0;
}
