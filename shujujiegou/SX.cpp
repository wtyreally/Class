#include <stdio.h>
#include <stdlib.h>
#define MAXNUM 20
#define true 1
#define false 0

typedef struct
{  
      int data[MAXNUM];
      int length;
}list_type; 

//创建顺序表函数 
void createlist(list_type *lp)
{
  int i, elem;
  lp->length=0;
  printf("\n请输入顺序表数据\n");
  for(i=0; i< MAXNUM; i++)
  {
        scanf(" %d", &elem);
        if(elem== -1)
        {
            break;
        }
        lp->data[i]=elem;
        lp->length++;
  }
}

//遍历元素并依次输出函数
void showlist(list_type *lp)
{
  int i;
  printf("\nThese %d records are:\n", lp->length);
  if(lp->length<=0)
  {
       printf("没有数据!\n");
       return;
  }
  for(i=0; i<lp->length; i++)
      printf(" %d ", lp->data[i]);
  printf("\n表的长度为:%d", lp->length);
}

//插入函数，成功返回true，反之返回false。
int insertlist(list_type *lp, int new_elem, int i)
{  int j;
    if(lp->length>=MAXNUM)
    {
        printf("插入失败，列表已满");
        return(false);
    }
   if(i<1 || i>lp->length+1)
   {
        printf("\n%d插入成功",i);
        return(false);
   }
   for(j=lp->length;j>=i-1;j--){
    lp->data[j]=lp->data[j-1];
   }
   lp->data[i-1]=new_elem;
   lp->length++;
   //放入新元素;
   //表长度增加;
   return(true);
}

//删除函数，成功返回true，反之返回false。
int deletelist(list_type *lp, int i)
{
   int j;
   if(i<1 || i>lp->length)
   {
        printf("元素不存在");
        return(false);
   }
   for(j=i-1;j<lp->length-1;j++){
    lp->data[j]=lp->data[j+1];
   }
   lp->length--;
   //表长度减少;
   return(true);
}

//找位置并插入数据
int insert_in_order(list_type *lp,int data)
{
	int i,j;
	if(lp->length>=MAXNUM)
	{
		printf("插入失败，列表已满");
		return false;
	} 
	else
	{
		for(i=0;i<lp->length;i++)
		{
			if(lp->data[i]>=data)
			{
				j=i;
				lp->length++;
				break;
			}
		}
		for(i=lp->length-1;i>j;i--)
		{
			lp->data[i]=lp->data[i-1]; 
		}
		lp->data[j]=data;
	}
} 

//反序
 void reverse_list(list_type *lp)
 {
 	int temp,i=0;
 	for(i=0;i<lp->length/2;i++)
 	{
 		temp=lp->data[i];
 		lp->data[i]=lp->data[lp->length-1-i];
 		lp->data[lp->length-i-1]=temp;
 	}
 }

//主函数，按要求调用已编写好的各函数
int main()
{
    list_type list;
    int i, data;
    createlist(&list);
    showlist(&list);
    printf("\ninsert:Enter i and data :\n");
    scanf("%d %d", &i, &data);
    insertlist(&list, data, i);
    printf("\nlist after insert:\n");
    showlist(&list);
    printf("\ndelete:Enter i:\n");
    scanf("%d", &i);
    deletelist(&list, i);
    printf("\nlist after delete:\n");
    showlist(&list);
    printf("\ninsert:Enter data :\n");
    scanf("%d", &data);
    insert_in_order(&list,data);
    printf("\nlist after insert:\n");
    showlist(&list);
    reverse_list(&list);
    printf("\nlist after reverse:\n");
    showlist(&list);
    return 0;
}
