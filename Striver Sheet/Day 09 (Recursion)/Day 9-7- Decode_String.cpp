class Solution {
		public:
			string decodeString(string s) {
				string ans="";
				int n=s.size();
				stack<string> st;
				for(int i=0;i<n;i++)
				{
					if(s[i]=='[')
						continue;
					else if(s[i]==']')
					{
						string rep=st.top();
						st.pop();

						string estr="";
						if(!st.empty() && isdigit(st.top()[0]))
						{
						int times=stoi(st.top());
						st.pop();
						while(times--)
						{
							estr+=rep;
						}
						}
						if(!st.empty() && !isdigit(st.top()[0]))
						{   string prev=st.top();
							st.pop();
						st.push(prev+estr);
						}
						else
							st.push(estr);
					}
					else
					{
						if(isdigit(s[i]))
						{
							if(i>0 && isdigit(s[i-1]))
								{
									string str=st.top();
									st.pop();
									int num=stoi(str);
									int d=s[i]-'0';
									st.push(to_string(num*10+d));
								}
								else
									st.push(to_string(s[i]-'0'));
						}
						else if(!st.empty() && isalpha(st.top()[0]))
						{
							string str=st.top();
							st.pop();
							st.push(str.append(1,s[i]));
						}
						else
						{
							string str="";
							st.push(str+s[i]); 
						}
					}
				   // cout<<st.top()<<endl;
				}

				while(!st.empty())
				{
				ans=st.top()+ans;
				st.pop();
				}
				return ans;
			}
		};
