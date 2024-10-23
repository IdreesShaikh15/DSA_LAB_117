bool isValid(char* c)
 {
    int len =strlen(c);
    char stack[len];
    int top = -1;
    for(int i=0;i<len;i++){
        if(c[i]=='(' || c[i] == '{' || c[i] == '[' ){
            stack[++top] = c[i];
        }else{
            if(top == -1 ||( c[i]==')'&&stack[top] != '(')||(c[i]=='}'&&stack[top] != '{')||(c[i]==']'&&stack[top]!='[')){
                return false;
            } 
            top--;
        } 
    }  
    return top == -1; 
}
