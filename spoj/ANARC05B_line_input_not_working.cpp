#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
vector<int> getvect(string str)
{
    vector<int> result;
    string temp="";
    for(int i=0;i<str.size();i++)
    {
        if(str[i]==' ')
        {
            if(temp!="")
            {
                result.push_back(stoi(temp));
            }
            temp="";
        }
        else
        {
            temp.push_back(str[i]);
        }
    }
    if(temp!="")
    {
        result.push_back(stoi(temp));
    }
    return result;
}
ll getsum(vector<int> vec,int n,int m)
{
    ll sum=0;
    for(int i=n;i<=m;i++)
    {
        sum+=vec[i];
    }return sum;
}
int main()
{
    string str;
    while(1)
    {
        getline(cin,str);
        if(str=="0")
        break;
        int i=0;
        string temp;
        while(str[i]!=' ')
        {
            temp.push_back(str[i]);
            i++;
        }
        int N=stoi(temp);
        vector<int> arr1=getvect(str.substr(i+1));
        map<int,int> mapa;
        for(i=0;i<arr1.size();i++)
        {
            mapa.insert(make_pair(arr1[i],i));
        }
        str="";temp="";
        getline(cin,str);
        i=0;
        while(str[i]!=' ')
        {
            temp.push_back(str[i]);
            i++;
        }
        int M=stoi(temp);
        long long resultsum=0;
        temp="";
        ll arr1sum=0;
        ll arr2sum=0;
        int arr1lastpos=0;
        
        int arr1pos=0;
        int sudo=0;
        for(int j=i+1;j<str.size();j++)
        {
            if(str[j]==' ')
            {
                if(temp!="")
                {   
                    sudo=stoi(temp);
                    arr2sum+=sudo;
                    temp="";
                    if(mapa.find(sudo)!=mapa.end())
                    {
                        // cout<<" T POINT "<<sudo<<endl;
                        arr1pos=mapa[sudo];
                        arr1sum=getsum(arr1,arr1lastpos,arr1pos);
                        arr1lastpos=arr1pos+1;
                         if(arr1sum>arr2sum)
                        {
                            resultsum+=arr1sum;
                            // cout<<" T POINT "<<sudo<<"Add SUM"<<arr1sum<<endl;
                        }
                        else
                        {
                            resultsum+=arr2sum;
                            // cout<<" T POINT "<<sudo<<"Add SUM"<<arr2sum<<endl;
                        }
                        arr2sum=0;
                        arr1sum=0;
                    }    
                }
            }
            else
            {
                temp.push_back(str[j]);
            } 
        }

        if(temp!="")
        {   
            sudo=stoi(temp);
            arr2sum+=sudo;
            temp="";
            if(mapa.find(sudo)!=mapa.end())
            {
                //  cout<<" T POINT "<<sudo<<endl;
                arr1pos=mapa[sudo];
                arr1sum=getsum(arr1,arr1lastpos,arr1pos);
                arr1lastpos=arr1pos+1;
                if(arr1sum>arr2sum)
                {
                    resultsum+=arr1sum;
                    // cout<<" T POINT "<<sudo<<"Add SUM"<<arr1sum<<endl;
                }
                else
                {
                    resultsum+=arr2sum;
                    // cout<<" T POINT "<<sudo<<"Add SUM"<<arr2sum<<endl;
                }
                
                
                arr2sum=INT_MIN;
                arr1sum=0;
            }    
   
        }
        if(arr1lastpos<arr1.size())
        {
            
            arr1sum=getsum(arr1,arr1lastpos,arr1.size()-1);
            // cout<<" T POINT X "<<arr1sum<<"arr2sum "<<arr2sum<<endl;
            resultsum+=arr1sum>arr2sum?arr1sum:arr2sum;
        }
        else
        {
           if(arr2sum>INT_MIN)
           resultsum+=arr2sum;
        //    cout<<" T POINT "<<arr2sum<<endl;
        }
        cout<<resultsum<<endl;

    }


}

/*
13 

*/