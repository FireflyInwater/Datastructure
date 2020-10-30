//字符串：：序列
//Pattern Matching : 子串去匹配字符串，得到第一次出现的位置

//朴素算法： 每次失配，S串的索引i定位的本次尝试匹配的第一个字符的后一个。P串的索引j定位到1；T(n)=O(n*m)

//KMP算法： 每次失配，S串的索引i不动，P串的索引j定位到某个数。T(n)=O(n+m)，时间效率明显提高

#include<iostream>
#include<string>
#include<vector>


int index(std::string src,std::string target){
    //朴素匹配算法。返回target串在src串出现的第一个位置。若匹配失败，返回-1；
    int i = 0,j =0;
    while (i<src.length()&&j<target.length())
    {
        if(src[i]==target[j]){ //字母相等就继续
            ++i;
            ++j;
        }
        else //出现不等，回退指针。target串回到第一个字母j=0开始。src串回到刚才的开始的下一个字母
        {
            i = i-j+1;
            j = 0;
        }
    }
    if(j=target.length()) //说明匹配到最后一个也相等，所以j=target.length。说明匹配成功了。
        return  i - target.length();
    else
        return -1;
}


/*返回子串的next数组*/
void get_next(std::string T, int *next){
    int i =0,j = -1;
    next[0] = -1;//串首的j = -1；
    while (i<T.length())
    {
        if(j == -1 || T[i] ==T[j]){
            ++i;
            ++j;
            next[i] = j;
        }
        else
            j = next[j];
    }
}

int KmpSearch(std::string srcString,std::string targetString)  
{  
    int i = 0;  
    int j = 0;  
    int next [255];
    get_next(targetString,next);
    while (i < srcString.length() && j < targetString.length())  
    {  
        //①如果j = -1，或者当前字符匹配成功（即S[i] == P[j]），都令i++，j++      
        if (j == -1 || srcString[i] == targetString[j])  
        {  
            i++;  
            j++;  
        }  
        else  
        {  
            //②如果j != -1，且当前字符匹配失败（即S[i] != P[j]），则令 i 不变，j = next[j]      
            //next[j]即为j所对应的next值        
            j = next[j];  
        }  
    }  
    if (j == targetString.length())  
        return i - j;  
    else  
        return -1;  
}  

int main(){
    std::string srcstring = "goodgoogle";
    std::string targetstring  = "google";
    std::cout<<index(srcstring,targetstring)<<std::endl;
    std::cout<<KmpSearch(srcstring,targetstring)<<std::endl;
    return 0;
}