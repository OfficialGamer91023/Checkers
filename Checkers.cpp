#include <iostream>
using namespace std;
class piece
{
    private:
    string player;
    bool isKing;
    bool jump;
    
    public:
    friend void assign();
    friend bool validate(int,int,int,int);
    friend void move(int,int,int,int);
    friend void display();
    friend bool check(int,int);
    friend int totalmoves();
    friend bool jumpcheck(int,int);
    friend void jumpable(int,int);
    
    
}board[8][8];

int xin,yin,xold,yold,rplayer=12,wplayer=12,count=0,jumpr,jumpw;bool nomover,nomovew;


void assign()
{
    int dispx=0,dispy=0;
    

     for(int i = 0;i<8;i++)
    {
        for(int j = 0;j<8;j++)
        {
            if(i==0||i==2)
            {
                if(j%2 != 0)
                {
                    board[i][j].player="W";
                    


                }
                else{
                    board[i][j].player="-";
                }
                

            }
            

            else if(i==5||i==7)
            {
                if(j%2 == 0)
                {
                    board[i][j].player="R";
                
                   


                }
                else{
                    board[i][j].player="-";
                }
                

            }
            else if(i==1)
            {
                if(j%2 == 0)
                {
                    board[i][j].player="W";
                    
                   



                }
                else{
                    board[i][j].player="-";
                }
                

            }
            
            else if(i==6)
            {
                if(j%2 != 0)
                {
                    board[i][j].player="R";
                    
                   


                }
                else{
                    board[i][j].player="-";
                }
                

            }

            else
            {
                board[i][j].player="-";
            }
            
            


        }
        

    }

    for(int i = 0;i<8;i++)
    {
        
        for(int j = 0;j<8;j++)
        {   
            if(j==0)
            {   dispx++;
                cout<<dispx<<"  ";


            }
            
            cout<<board[i][j].player<<"  ";
            



        }
        cout<<endl;
        if(i==7)
        {
            
            while(dispy<9)
            {
                cout<<dispy<<"  ";
                dispy++;
            }
            cout<<endl;
        }


    }
    

}

bool validate(int ox,int oy,int nx,int ny)
{
    if (ox>8||ox<0||oy>8||oy<0||nx<0||ny>8||ny<0||ny>8)
    {
        
        return true;
    
    }
    
    if(board[oy][ox].player=="R")
    {
   
        if(ox-nx==1&&oy-ny==1)
        {
            if(board[ny][nx].player=="R")
            {
                
                return true;


            }
            else if(board[ny][nx].player=="W"&&board[ny-1][nx-1].player=="W"||board[ny][nx].player=="W"&&board[ny-1][nx-1].player=="R")
            {
                return true;
            }
            
            else
            {
                
                return false;
            }

        }
        
        else if(oy-ny==1&&nx-ox==1)
        {
             if(board[ny][nx].player=="R")
            {
                
                return true;

            }
            else if(board[ny][nx].player=="W"&&board[ny-1][nx+1].player=="W"||board[ny][nx].player=="W"&&board[ny-1][nx+1].player=="R")
            {
                return true;
            }
            else
            {
                
                return false;
            }

        }
        
        else if(board[oy][ox].isKing==true)
        {
            
            if(ox-nx==1&&ny-oy==1)
            {
                if(board[ny][nx].player=="R")
                {
                
                    return true;

                }
                else if(board[ny][nx].player=="R"&&board[ny+1][nx-1].player=="R"||board[ny][nx].player=="R"&&board[ny+1][nx-1].player=="W")
            {
                return true;
            }

                else
                {
                    return false;
                }

            }
            else if(ny-oy==1&&nx-ox==1)
            {
                if(board[ny][nx].player=="R")
                {
                
                    return true;

                }
                else if(board[ny][nx].player=="R"&&board[ny+1][nx+1].player=="R"||board[ny][nx].player=="R"&&board[ny+1][nx+1].player=="W")
                {
                    return true;
                }
            
                else
                {
                    return false;
                }

            }

        }
        else
        {
            
            return true;
        
        }
    }

    else if(board[oy][ox].player=="W")
    {
        if(nx-ox==1&&ny-oy==1)
        {
            if(board[ny][nx].player=="W")
            {
                
                return true;

            }
            else if(board[ny][nx].player=="R"&&board[ny+1][nx+1].player=="R"||board[ny][nx].player=="R"&&board[ny+1][nx+1].player=="W")
            {
                return true;
            }
            
            else
            {
                
                return false;
            
            }

        }
        else if(ny-oy==1&&ox-nx==1)
        {
             if(board[ny][nx].player=="W")
            {
                
                return true;
                

            }
            else if(board[ny][nx].player=="R"&&board[ny+1][nx-1].player=="R"||board[ny][nx].player=="R"&&board[ny+1][nx-1].player=="W")
            {
                return true;
            }
            
            else
            {
                return false;
            }

        }
        else if(board[oy][ox].isKing==true)
        {
            
           if(ox-nx==1&&oy-ny==1)
            {
                if(board[ny][nx].player=="W")
                {
                
                    return true;

                }
                else if(board[ny][nx].player=="W"&&board[ny-1][nx-1].player=="W"||board[ny][nx].player=="W"&&board[ny-1][nx-1].player=="R")
            {
                return true;
            }
                
                else
                {
                    
                    return false;
                
                }

            }
            else if(oy-ny==1&&nx-ox==1)
            {
                if(board[ny][nx].player=="W")
                {
                
                    return true;

                
                }
                else if(board[ny][nx].player=="W"&&board[ny-1][nx+1].player=="W"||board[ny][nx].player=="W"&&board[ny-1][nx+1].player=="R")
            {
                return true;
            }
            
                
                else
                {
                    
                    return false;
                
                }

            }
        }
        else
        {
            
            return true;
        
        }
    }
    


}

void jumpable(int i,int j)
{
	
	if(count%2==0)
    {
        
	if(board[i][j].player=="R"||board[i][j].player=="W"&&board[i][j].isKing==true){
	
    if(board[i-1][j+1].player=="W"&&validate(i,j,i-1,j+1)==false)
    {
        board[i][j].jump=true;
        jumpr++;
        
    }
    else if(board[i-1][j-1].player=="W"&&validate(i,j,i-1,j-1)==false)
    {
        board[i][j].jump=true;
        jumpr++;
        
    }
    
    else
    {
        board[i][j].jump=false;
        
    }
}
    }
    else
    {
    if(board[i][j].player=="W"||board[i][j].player=="R"&&board[i][j].isKing==true){
	

    if(board[i+1][j-1].player=="R"&&validate(i,j,i+1,j-1)==false)
    {
         board[i][j].jump=true;
         jumpw++;
         
    }
    else if(board[i+1][j+1].player=="R"&&validate(j,i,j+1,i+1)==false)
    {
        board[i][j].jump=true;
        jumpw++;
        
    }
    
    else{
        board[i][j].jump=false;
    }
}
    }
}


void move(int ox,int oy,int nx,int ny)
{
    
    if(board[oy][ox].player=="R")
    {

        if((ny==0)||(ny==1 && board[ny][nx].player=="W"))
        {
            board[oy][ox].isKing=true;
            

    

        }

        if(board[ny][nx].player=="W"&&(ox-nx==1&&oy-ny==1))
        {
                
            board[ny][nx].player="-";
            board[ny-1][nx-1]=board[oy][ox];
            board[oy][ox].player="-";
            wplayer--;
            
        }

        else if(board[ny][nx].player=="W"&&(oy-ny==1&&nx-ox==1))
        {
                
            board[ny][nx].player="-";
            board[ny-1][nx+1]=board[oy][ox];
            board[oy][ox].player="-";
            wplayer--;
            
        }


        
        else
        {
            
            board[ny][nx]=board[oy][ox];
            board[oy][ox].player="-";
            
        

        }

        
        
    }

    if(board[oy][ox].player=="W")
    {
        if((ny==7))
        {
            board[oy][ox].isKing=true;
            
    

        }
        if(board[ny][nx].player=="R"&&(ny-oy==1&&ox-nx==1))
        {
                
            board[ny][nx].player="-";
            board[ny+1][nx-1]=board[oy][ox];
            board[oy][ox].player="-";
            rplayer--;
            
        }
        else if(board[ny][nx].player=="R"&&(nx-ox==1&&ny-oy==1))
        {
            board[ny][nx].player="-";
            board[ny+1][nx-1]=board[oy][ox];
            board[oy][ox].player="-";
            rplayer--;
        }
        else
        {
            
            board[ny][nx]=board[oy][ox];
            board[oy][ox].player="-";
            rplayer--;
        

        }

        
    }

    
    



    

}

void display()
{
    int dispx=0,dispy=0;
    for(int i = 0;i<8;i++)
    {
        
        for(int j = 0;j<8;j++)
        {   
            if(j==0)
            {   dispx++;
                cout<<dispx<<"  ";


            }
            
            cout<<board[i][j].player<<"  ";
            



        }
        cout<<endl;
        if(i==7)
        {
            
            while(dispy<9)
            {
                cout<<dispy<<"  ";
                dispy++;
            }
            cout<<endl;
        }


    }
}

bool check(int ox,int oy)
{
    if(ox>8||ox<0||oy>8||oy<0)
    {

     return true;
    
    }
    else if(board[oy][ox].player=="-")
    {
        return true;
    }
    else if(count%2==0)
    {
        if(board[oy][ox].player=="W")
        {
            return true;
        }
    }
    else if(count%2!=0)
    {
        if(board[oy][ox].player=="R")
        {
            return true;
        }

    }
    else
    {
        return false;
    }


}

int totalmoves()
{
    
    if(count%2==0)
    {
        for(int i =0;i<8;i++)
        {
            for(int j = 0;j<8;j++)
            {
                jumpable(i,j);
                if(board[i][j].player=="R")
                {
                    if(validate(j,i,j+1,i-1)==false||validate(j,i,j-1,i-1)==false||validate(j,i,j-1,i+1)==false||validate(j,i,j+1,i+1)==false)
                    {
                        nomover = false;
                        
                        
                    }

                    
                    
                    

                }
                
            }
            
        }
    }

    else if(count%2!=0)
    {
        for(int i =0;i<8;i++)
        {
            for(int j = 0;j<8;j++)
            {
                if(board[i][j].player=="W")
                {
                    if(validate(j,i,j+1,i-1)==false||validate(j,i,j-1,i-1)==false||validate(j,i,j-1,i+1)==false||validate(j,i,j+1,i+1)==false)
                    {
                        nomovew = false;


                    }

                    


                }
                
            }
            
        }
    }
    
}

bool jumpcheck(int ox,int oy)
{
    
    if(board[oy][ox].jump==true)
    {
        
        return true;
    }
    
}



int main()
{
    
    assign();
    if(count%2==0)
    {
        cout<<"Red to move"<<endl;
    }
    else
    {
        cout<<"White to move"<<endl;
    }
    cout<<"please enter the x and y coordinates of the peice you want to move"<<endl;
    cin>>xold>>yold;
    
    while(check(xold-1,yold-1))
    {
        if(count%2==0)
        {
            cout<<"Please select the correct red piece"<<endl;
        }
        else if(count%2!=0)
        {
            cout<<"Please select the correct white piece"<<endl;
        }
        cin>>xold>>yold;
    }
    
    cout<<"please enter where you want to move the piece"<<endl;
    cin>>xin>>yin;
     
    while(validate(xold-1,yold-1,xin-1,yin-1))
    {
            cout<<"This move is not possible.Try again"<<endl;
            cin>>xin>>yin;
    }
    
    while(rplayer!=0||wplayer!=0||nomover==true||nomovew==true)
    {
        
        jumpr=0;
        jumpw=0;
        move(xold-1,yold-1,xin-1,yin-1);
        
        display();
        count++;
        totalmoves();
        if(nomover==true||nomovew==true)
        {
            break;
        }
        if(count%2==0)
        {
            cout<<"Red to move"<<endl;
        }
        else
        {
            cout<<"White to move"<<endl;
        }
        
        if(jumpr>0&&count%2==0)
        {
            cout<<"Jump is available for red"<<endl;
        }
        if(jumpw>0&&count%2!=0)
        {
            cout<<"Jump is available for white"<<endl;
        }
        
        cout<<"please enter the x and y coordinates of the peice you want to move"<<endl;
        cin>>xold>>yold;
        if(jumpr>0||jumpw>0)
        {
            while(jumpcheck(xold-1,yold-1)==false)
            {   cout<<"Jump is available. Please enter correct piece"<<endl;
            
                cin>>xold>>yold;
            }
        }
        while(check(xold-1,yold-1))
        {
        if(count%2==0)
        {
            cout<<"Please select the correct red piece"<<endl;
        }
        else if(count%2!=0)
        {
            cout<<"Please select the correct white piece"<<endl;
        }
        cin>>xold>>yold;
        }

        cout<<"please enter where you want to move the piece"<<endl;
        cin>>xin>>yin;
        while(validate(xold-1,yold-1,xin-1,yin-1))
        {
            cout<<"This move is not possible.Please select a piece and try again"<<endl;
            cin>>xold>>yold;
            while(check(xold-1,yold-1))
            {
                if(count%2==0)
                {
                    cout<<"Please select the correct red piece"<<endl;
                }
                else if(count%2!=0)
            {
                cout<<"Please select the correct white piece"<<endl;
            }
            cin>>xold>>yold;
            }
            cin>>xin>>yin;
        }

        

    
    }
    
    if(nomovew == true || wplayer == 0)
    {
        cout<<"Red wins"<<endl;
    }
    else
    {
        cout<<"white wins"<<endl;
    }
     
    







}




 
