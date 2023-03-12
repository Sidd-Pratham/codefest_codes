#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    int cnt=1;
    while(n--)
    {
        int h;
        cin>>h;
        float timer=0;
        float qa=0;
        float qn=0;
        for(int i=0;i<h;i++)
        {
            string sh;
            cin>>sh;
             stringstream ss(sh);
              vector<int> v;
               for (int i; ss >> i;) {
        v.push_back(i);
        if (ss.peek() == ',')
            ss.ignore();
    }
            int total,r,s,h;
            // cin>>total>>r>>s>>h;
            r=v[1];
            s=v[2];
            h=v[3];
            float walls=(r*3)+(s*4)+(h*6);
            qa=qa+(walls*1.5*(1.0/3.0));
            qn=qn+(walls*2.25*float(2.0/3.0));
            float t_a=walls*2.5*(1.0/3.0);
            float t_n=walls*3.25*(2.0/3.0);
            timer=timer+(t_a+t_n);
        }
        cout<<"case#"<<cnt<<":";
        cout<<fixed<<setprecision(2)<<timer<<" ";
        cout<<fixed<<setprecision(2)<<qa<<" ";
        cout<<fixed<<setprecision(2)<<qn<<endl;
        cnt++;
    }
	return 0;
}
