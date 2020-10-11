#include<bits/stdc++.h>  
    #define ll long long  
    using namespace std;  
    class node  
    {  
      public:  
      ll pre,suf,sum,result;  
      node()         //this is a constructor i.e. every new created object will have default value as below  
      {pre=suf=sum=result=INT_MIN;}//object.pre=INT_MIN,object.sum=INT_MIN etc.  
    };  
    node a[131080];  
    node search(ll q1,ll q2, ll l,ll r,ll pos)  
    {                                          //cout<<a[0].result<<"//"<<a[pos].result<<"////";  
      if(q2<l||r<q1)  
      return a[0];  
                                                
      else if(q1<=l&&r<=q2)  
      return a[pos];  
        
      else  
      {                                        //cout<<" l-"<<l<<" r-"<<r;  
        ll mid=(l+r)/2;   node x,y,z;  
        x=search(q1,q2,l,mid,pos*2);  
        y=search(q1,q2,mid+1,r,pos*2+1);  
                                              //cout<<" ^x- "<<x.suf<<" ^y- "<<y.pre<<"^^";  
        z.sum=x.sum+y.sum;  
        z.pre=max(x.pre, (x.sum+y.pre));  
        z.suf=max(y.suf, (y.sum+x.suf));                      //cout<<";;"<<pos<<".."<<z.result<<";;\n";  
        z.result=max(x.suf+y.pre, max(x.result,y.result));  
        return z;  
      }  
    }  
    //In this portion I have created the tree so that when query is asked we will have to traverse the tree only  
    //I am dividing the array g[] in half and multiplying pos(with initial value 1) integer by 2 which means   
    //suppose pos is one then it will represent 2 child i.e. pos*2=2, and pos*2+1=3 and array is divided in half  
    // means first child will represent first half of array and other child will represent other half and so on.  
    //Now part where I assign values--  
    //a[pos].sum is sum of 2 child at pos  
    //.pre means max sequence starts with first element of first child  
    //.suf means max sequence starts with last element of 2nd child  
    //idea behind suf & pre is in any query either max sequence will start with beginning of query or the end of query or it will   
    //be a sequence in the middle that do not touches any boundary of quuery.  
    //.result means suffix of first child + prefix of second child (this is the middle sequence I was talking about) or prefix of   
    //first child or prefix of second child or suffix of first or second child. Whichever is max.  
    void update(ll l, ll r, ll pos,ll g[])  
    {  
      if(l==r)  
      {  
        a[pos].pre=a[pos].suf=a[pos].sum=a[pos].result=g[l];  
        return;  
      }  
      ll mid=(l+r)/2;  
      update(l,mid,pos*2,g);  
      update(mid+1,r,pos*2+1,g);  
      a[pos].sum=a[pos*2].sum+a[pos*2+1].sum;  
      a[pos].pre=max(a[pos*2].pre,(a[pos*2].sum+a[pos*2+1].pre));  
      a[pos].suf=max(a[pos*2+1].suf,(a[pos*2+1].sum+a[pos*2].suf));  
      a[pos].result=max(a[pos*2].suf+a[pos*2+1].pre,max(a[pos*2].result,a[pos*2+1].result));  
      return;  
    }  
    int main()  
    {  
      ll n;  
      cin>>n;  
      ll i,j;                                     //cout<<a[1].pre<<"....";  
      //In this part I am creating tree(by update function) --  
      ll g[n];  
      for(i=0;i<n;i++)  
      cin>>g[i];  
      update(0,n-1,1,g);  
      //Now my tree has been created  
      /*  
      cout<<"\nsum --\n";  
      for(int i=0;i<28;i++)  
      {  
        if(a[i].sum>4967240||a[i].sum<-4967240)  
        cout<<"FF"<<i<<" ";  
        else  
        cout<<a[i].sum<<" ";  
      }  
      cout<<"\npre --\n";  
      for(int i=0;i<28;i++)  
      {  
        if(a[i].pre>4967240||a[i].pre<-4967240)  
        cout<<"FF"<<i<<" ";  
        else  
        cout<<a[i].pre<<" ";  
      }  
      cout<<"\nsuf --\n";  
      for(int i=0;i<28;i++)  
      {  
        if(a[i].suf>4967240||a[i].suf<-4967240)  
        cout<<"FF"<<i<<" ";  
        else  
        cout<<a[i].suf<<" ";  
      }  
      cout<<"\nresult --\n";  
      for(int i=0;i<28;i++)  
      {  
        if(a[i].result>4967240||a[i].result<-4967240)  
        cout<<"FF"<<i<<" ";  
        else  
        cout<<a[i].result<<" ";  
      }  
      cout<<"\n";*/  
      //Query part- I am storing all values such as suffix(suf), prefix(pre) etc, in newly declared object 'c'  
      // since returned value is also object so pre of returned object from search function will be stored in pre of 'c',  
      //same for suf,sum etc  
      ll m;  
      cin>>m;  
      while(m--)  
      {  
        ll aa,b;  
        cin>>aa>>b;  
        node c=search(aa-1,b-1,0,n-1,1);  
        cout<<c.result<<"\n";  
      }  
      return 0;  
    }   