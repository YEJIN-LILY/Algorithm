#include <iostream>
using namespace std;

/*
흩날리는 모래의 좌표만 생각할 것이다.
이 때 주의해야 할 것은, left, up, right, down에 따라서 좌표이동값이 달라진다는 것이다.
2,10,7,1,5,10,7,1,2 순으로 읽기로 고정했기 때문에
좌표이동값은 그에 맞추어서 각각 다르게 설정한다.
여기서 시간 많이 뺏겼다..ㅠㅠ
*/
int N,answer;
int A[500][500];
int sand[9]={2,10,7,1,5,10,7,1,2};
int sand_x[4][9]={{-2,-1,-1,-1,0,1,1,1,2}, //left
		   {0,-1,0,1,-2,-1,0,1,0}, //up
		   {2,1,1,1,0,-1,-1,-1,-2}, //right
		   {0,1,0,-1,2,1,0,-1,0}}; //down

int sand_y[4][9]={{0,-1,0,1,-2,-1,0,1,0}, //left
		  {2,1,1,1,0,-1,-1,-1,-2}, //up
		  {0,1,0,-1,2,1,0,-1,0}, //right
		  {-2,-1,-1,-1,0,1,1,1,2}}; //down


void rotate_left(int sx,int sy,int dx,int dy){ //출발, 목적지 좌표
	for(int i=1;i<=sy-dy;i++){
		int a=A[sx][sy-i]; //한 칸 이동한 좌표의 모래의 양
		
		
		for(int j=0;j<9;j++){
			int nx=sx+sand_x[0][j]; //모래가 흩날릴 좌표
			int ny=sy-i+sand_y[0][j];
			
			if(nx<0||ny<0||nx>=N||ny>=N){ //모래 벗어나면
				answer+=(int)(A[sx][sy-i]*sand[j]/100);
			}else{
				A[nx][ny]+=(int)(A[sx][sy-i]*sand[j]/100); //흩날리는 모래의 양 더해줌
			}
			a-=(int)(A[sx][sy-i]*sand[j]/100); //남은 모래의 양
		}
		A[sx][sy-i]=0; //흩날리는 시작점은 다 흩날린 것이므로 0으로 만들어줌!
		if(sx<0||sy-i-1<0||sy-i-1>=N||sx>=N){ //좌표가 판 바깥으로 나갈 수 있다...이것도 고려!!!
			answer+=a;
		}else
			A[sx][sy-i-1]+=a; //남은 모래의 양
		
	}

}

void rotate_down(int sx,int sy,int dx,int dy){
	for(int i=1;i<=dx-sx;i++){
		int a=A[sx+i][sy]; //한 칸 이동한 좌표의 모래의 양
		
		
		for(int j=0;j<9;j++){
			int nx=sx+i+sand_x[3][j]; //모래가 흩날릴 좌표
			int ny=sy+sand_y[3][j];
			
			if(nx<0||ny<0||nx>=N||ny>=N){ //모래 벗어나면
				answer+=(int)(A[sx+i][sy]*sand[j]/100);
			}else{
				A[nx][ny]+=(int)(A[sx+i][sy]*sand[j]/100); //흩날리는 모래의 양 더해줌
			}
			a-=(int)(A[sx+i][sy]*sand[j]/100); //남은 모래의 양
		}
		A[sx+i][sy]=0;
		if(sx+i+1<0||sy<0||sy>=N||sx+i+1>=N){
			answer+=a;
		}else
			A[sx+i+1][sy]+=a; //남은 모래의 양
		
	}
}

void rotate_right(int sx,int sy,int dx,int dy){
	for(int i=1;i<=dy-sy;i++){
		int a=A[sx][sy+i]; //한 칸 이동한 좌표의 모래의 양
		
		
		for(int j=0;j<9;j++){
			int nx=sx+sand_x[2][j]; //모래가 흩날릴 좌표
			int ny=sy+i+sand_y[2][j];
			
			if(nx<0||ny<0||nx>=N||ny>=N){ //모래 벗어나면
				answer+=(int)(A[sx][sy+i]*sand[j]/100);
			}else{
				A[nx][ny]+=(int)(A[sx][sy+i]*sand[j]/100); //흩날리는 모래의 양 더해줌
			}
			a-=(int)(A[sx][sy+i]*sand[j]/100); //남은 모래의 양
		}
		A[sx][sy+i]=0;
		if(sx<0||sy+i+1<0||sy+i+1>=N||sx>=N){
			answer+=a;
		}else
			A[sx][sy+i+1]+=a; //남은 모래의 양
		
	}
}

void rotate_up(int sx,int sy,int dx,int dy){
	for(int i=1;i<=sx-dx;i++){
		int a=A[sx-i][sy]; //한 칸 이동한 좌표의 모래의 양
		
		
		for(int j=0;j<9;j++){
			int nx=sx-i+sand_x[1][j]; //모래가 흩날릴 좌표
			int ny=sy+sand_y[1][j];
			
			if(nx<0||ny<0||nx>=N||ny>=N){ //모래 벗어나면
				answer+=(int)(A[sx-i][sy]*sand[j]/100);
			}else{
				A[nx][ny]+=(int)(A[sx-i][sy]*sand[j]/100); //흩날리는 모래의 양 더해줌
			}
			a-=(int)(A[sx-i][sy]*sand[j]/100); //남은 모래의 양
		}
		A[sx-i][sy]=0;
		
		if(sx-i-1<0||sy<0||sy>=N||sx-i-1>=N){
			answer+=a;
		}else
			A[sx-i-1][sy]+=a; //남은 모래의 양
	}
}

void tornado(int x,int y){
	int nx=x; //목적지
	int ny=y;
	
	int ox=x; //출발
	int oy=y;
	
	for(int i=1;i<=N-1;i++){
		if(i==N-1){ //마지막에는 총 3번 움직임
			ny=oy+i;
			rotate_right(ox,oy,nx,ny);
			oy=ny; //이동하면 이제 그곳이 출발좌표가 되는 것임..갱신해 줘야한다!!!
			nx=ox-i;
			rotate_up(ox,oy,nx,ny);
			ox=nx;
			ny=oy-i;
			rotate_left(ox,oy,nx,ny);
			oy=ny;
		}
		else if(i%2==0){
			ny=oy+i;
			rotate_right(ox,oy,nx,ny);
			oy=ny;
			nx=ox-i;
			rotate_up(ox,oy,nx,ny);
			ox=nx;
		}else{
			ny=oy-i;
			rotate_left(ox,oy,nx,ny);
			oy=ny;
			nx=ox+i;
			rotate_down(ox,oy,nx,ny);
			ox=nx;
		}
	}
}



int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	cin>>N;
	
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cin>>A[i][j];
		}
	}
	
	tornado(N/2,N/2);
	cout<<answer;
	
}
