#include<stdio.h>
int main()
{
    int n,i,s=0,count=0,j,k,l;
    scanf("%d",&n);
    int a[n+1];
    l=1<<n;
    for (i=0;i<n;i++) scanf("%d",&a[i]);
    for (i=1;i<l;i++) {
    k=i;
    for(j=0;j<n;j++) {
        if (k & 1) s+=a[j];
        k>>=1;
    }
    while (s&&(s%2==0)) s=s/2;
    if (s==1) count++;
    s=0;
    }
    printf("%d",count);  
}

