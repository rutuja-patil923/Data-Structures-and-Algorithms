int inSequence(int A, int B, int C){
        
        if(C==0)
        {
            if(A==B) 
                return 1;
            return 0;
        }
        
        // calculated value of n
        int check = (B-A)/C + 1;
        
        // n'th term
        int result = A + (check-1)*C;
        
        // check if n'th term matches with given B
        if(B==result && check >0)
            return 1;
        return 0;
}