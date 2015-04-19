#include <simplecpp>
#include <string>
#include <time.h>
int speed=1;
bool Lies_on_snake(double*a,double*b,int  x,int y,int no_circles)
{
	bool mano=false;

	for (int i=0; i<no_circles; i++) {
		if (sqrt(((x-a[i])*(x-a[i]))+((y-b[i])*(y-b[i])))<20) {
			mano=true;
			break;
		}
	}

	return mano;//we are returning the true when it is inside of the snake @@@@@@@@
}

class button
{
public:

	double width;
	double height;
	double clx;
	double cly;
	button(const char *tptr,double w,double h,double x,double y,const char *colour) {
		width=w;
		height=h;
		clx=x;
		cly=y;
		Rectangle r(clx,cly,width,height);
		r.setColor(COLOR(colour));
		r.setFill();
		r.imprint();
		Text t(x,y,tptr);
		t.imprint();
	}
void hide(){
	Rectangle r(clx,cly,width,height);
	r.setColor(COLOR(255,255,255));
		r.setFill();
		r.imprint();}

	bool inside(double clickx,double clicky) {
		return ((abs(clx-clickx)<=width/2)&&(abs(cly-clicky)<=height/2));
	}
};


struct rectangle {

	double cx,cy,height,width;
	Rectangle r;

	rectangle(double x, double y,double h,double w) {
		cx=x;
		cy=y;
		height =h;
		width =w;
		r.reset(x,y,h,w);
	}
	rectangle() {}
	void setColor(int x,int y,int z) {
		r.setColor(COLOR(x,y,z));
		r.setFill();
		r.imprint();
	}
	void setColor() {};
	bool verify(int x,int y) {
		if ((abs(x-cx)<=height/2)&&(abs(y-cy)<=width/2))return true;
		else return false;
	}
};
void level_game();
void mainpage();
void kill();
void how_to_play()
{
	//initCanvas("HOW TO PLAY",1200,800);
	button b1("INSTRUCTIONS",800,40,250,50,"green");
	button b2("1. The command 'f' is used to move the snake in rightward direction",800,40,250,100,"green");
	button b3("2. The command 'd' is used to move the snake in leftward direction",800,40,250,150,"green");
	button b4("3. The command 'r' is used to move the snake in upward direction",800,40,250,200,"green");
	button b5("4. The command 'c' is used to move the snake in downward direction",800,40,250,250,"green");
	button b6("5.The snake can not go in backward direction ",800,40,250,300,"green");
	button b7("6.If snakes strikes any wall or its own body it will be killed",800,40,250,350,"green");
	button b8("Main Menu",800,40,250,450,"green");

	while (true) {
		int next=getClick();
b1.hide();b2.hide();
b3.hide();	b4.hide();b5.hide();
b8.hide();	b7.hide();b6.hide();

		if (b8.inside(next/65536,next%65536)) {
			kill();

			break;
		}
	}
}
void speed_of_game()
{
	//initCanvas("DETERMINE SPEED",1200,800);
	button b1("select the level(speed) u want",1200,40,600,100,"yellow");
	button b2("level 1",100,40,250,50,"yellow");
	button b3("level 2",100,40,250,100,"yellow");
	button b4("level 3",100,40,250,150,"yellow");
	button b5("level 4",100,40,250,200,"yellow");
	button b6("level 5",100,40,250,250,"yellow");
	button b7("level 6",100,40,250,300,"yellow");
	button b8(" MAIN MENU",200,40,250,400,"yellow");

	while (true) {
		int next=getClick();

		if (b2.inside(next/65536,next%65536)) {
b1.hide();b2.hide();
b3.hide();	b4.hide();b5.hide();
b8.hide();	b7.hide();b6.hide();
			speed=1;
			kill();
			break;
		}

		if (b3.inside(next/65536,next%65536)) {
b1.hide();b2.hide();
b3.hide();	b4.hide();b5.hide();
b8.hide();	b7.hide();b6.hide();
			speed=2;
			kill();
			break;
		}

		if (b4.inside(next/65536,next%65536)) {
b1.hide();b2.hide();
b3.hide();	b4.hide();b5.hide();
b8.hide();	b7.hide();b6.hide();
			speed=3;
			kill();
			break;
		}

		if (b5.inside(next/65536,next%65536)) {
b1.hide();b2.hide();
b3.hide();	b4.hide();b5.hide();
b8.hide();	b7.hide();b6.hide();
			speed=4;
			kill();
			break;
		}

		if (b6.inside(next/65536,next%65536)) {
b1.hide();b2.hide();
b3.hide();	b4.hide();b5.hide();
b8.hide();	b7.hide();b6.hide();
			speed=5;
			kill();
			break;
		}

		if (b7.inside(next/65536,next%65536)) {
b1.hide();b2.hide();
b3.hide();	b4.hide();b5.hide();
b8.hide();	b7.hide();b6.hide();
			speed=6;
			kill();
			break;
		}

		if (b8.inside(next/65536,next%65536)) {
			b1.hide();b2.hide();
b3.hide();	b4.hide();b5.hide();
b8.hide();	b7.hide();b6.hide();
			kill();

			break;
		}
	}
}
void about_the_game()
{
	//initCanvas("About the Game",1200,800);
	button b1("ABOUT THE GAME",700,30,400,40,"green");
	button b2("Snake is a video game that originated during the late 1970s in arcades and ",700,40,400,80,"green");
	button b3(" has maintained popularity since then, becoming somethingof a classic. ",700,40,400,120,"green");
	button b4("Nokia phones in 1998, Snake found a massive audience.The Snake variety of games variety ",700,40,400,160,"green");
	button b5(" of games dates back to the arcade game Blockade, developed and published by  Gremlin in 1976.In 1978,",700,40,400,200,"green");
	button b6("Atari, Inc. released, as an unofficial port, an early home console  version of the Blockade concept,",700,40,400,240,"green");
	button b7("titled Surround. Surround was one of the nine Atari 2600 (VCS) launch titles,and s",700,40,400,280,"green");
	button b8("under the name Chase. That same year,a similar game was ",700,40,400,320,"green");
	button b9(" was also sold by Sears launched for the Bally Astrocade as Checkmate.",700,40,400,360,"green");
	button b11("to know more visit 'http://en.wikipedia.org/wiki/Snake_(video_game)'",700,40,400,400,"green");
	button b10(" MAIN MENU",700,40,400,450,"green");

	while (true) {
		int next=getClick();
b1.hide();b2.hide();
b3.hide();	b4.hide();b5.hide();
b8.hide();	b7.hide();b6.hide();b7.hide();b8.hide();
b9.hide();	b11.hide();b10.hide();

		if (b10.inside(next/65536,next%65536)) {

			kill();
			break;
		}
	}
}
void about_us()
{
	//initCanvas("about us",1200,800);
	button b1("ABOUT US",800,40,400,100,"red");
	button b2("we are students of Monday Batch",800,40,400,300,"red");
	button b3("140040040, 140040001, 140040001, 140110030....",800,40,400,340,"red");
	button b4("we are trying to make a snake game",800,40,400,380,"red");
	button b5("but working hard because of lack of time...",800,40,400,420,"red");
	button b6("and we have made as much improvements as we can..",800,40,400,460,"red");
	button b7("we could have made much better...",800,40,400,500,"red");
	button b10(" MAIN MENU",200,40,400,740,"red");

	while (true) {
		int next=getClick();
b1.hide();b2.hide();
b3.hide();b4.hide();
b5.hide();b6.hide();
b7.hide();
b10.hide();

		if (b10.inside(next/65536,next%65536)) {

			kill();
			break;
		}
	}
}




void level_of_the_game(int stage)
{
	double ro=10;
	int score=0;
	int p1,q1;
	//initCanvas("level ",800,900);
	Circle pointer;
	int  xpointer,ypointer;
	int initialx=randuv(0,800)/20;
	int initialy=randuv(0,800)/20;
	xpointer=initialx*20+10;
	ypointer=initialy*20;
	Rectangle re(400,815,800,10);
	re.setFill();
	re.imprint();
	Text score_text(100,850,"SCORE:");
	score_text.imprint();
	Text score1(200,850,score);
	int xxx=0;
	double x[100],y[100];
	Circle  c[100];
	int r=70;
	int no_of_circles=8;

	for (int i=0; i<8; i++) {
		x[i]=400+r;
		y[i]=400;
		r=r-20;
	}

	for (int i=0; i<8; i++) {
		c[i].reset(x[i],y[i],10);
	}

	wait(0.5);

	for (int i=1; i<8; i++) {
		c[i].setColor(COLOR("green"));
		c[i].setFill();
	}

	char command[2];
	command[0]='f';
	c[0].setColor(COLOR("red"));
	c[0].setFill();
	pointer.reset(xpointer,ypointer,ro);
	bool touch=false;
	int xx=1;

	while (true) {
		pointer.reset(xpointer,ypointer,ro);
		pointer.setColor(COLOR(xx%255,xx%255,xx%255));
		pointer.setFill(1);
		xx++;
		XEvent event;

		if (sqrt((((x[0]-xpointer)*(x[0]-xpointer))+((y[0]-ypointer)*(y[0]-ypointer)))<2*ro)) {
			score+=10;

			while (true) {
				double xoo,yoo;
				/*
Declare variable to hold seconds on clock.
*/
time_t seconds;
/*
Get value from system clock and
place in seconds variable.
*/
time(&seconds);
/*
Convert seconds to a unsigned
integer.
*/
srand((unsigned int) seconds);
/*
Output random values.
*/

				if (stage ==1) {
					xoo=randuv(20,800);
					yoo=randuv(20,800);
				}

				if (stage==2||stage==3) {
					xoo=randuv(50,760);
					yoo=randuv(50,770);
				}

				int p=xoo/20;
				int q=yoo/20;
				p1=p*20+10;
				q1=q*20;
				if (Lies_on_snake(x,y,p1,q1,no_of_circles)) {} else {
					xpointer=p1;
					ypointer=q1;
					break;
				}
			}

			pointer.reset(xpointer,ypointer,ro);
			c[no_of_circles].reset(x[no_of_circles-1],y[no_of_circles-1],ro);
			c[no_of_circles].setColor(COLOR("green"));
			c[no_of_circles].setFill(1);
			no_of_circles++;
			score1.reset(200,850,score);
		} else if (checkEvent(event)) {
			command[1]=charFromEvent(event);

			if ((command[0]=='f'||command[0]=='d')&&command[1]=='r') {
				for (int j=no_of_circles-1; j>0; j--) {
					x[j]=x[j-1];
					y[j]=y[j-1];
					c[j].reset(x[j],y[j],ro);
				}

				command[0]='r';
				y[0]=y[0]-2*ro;
				c[0].reset(x[0],y[0],ro);
			} else if ((command[0]=='f'||command[0]=='d')&&command[1]=='c') {
				for (int j=no_of_circles-1; j>0; j--) {
					x[j]=x[j-1];
					y[j]=y[j-1];
					c[j].reset(x[j],y[j],ro);
				}

				command[0]='c';
				y[0]=y[0]+2*ro;
				c[0].reset(x[0],y[0],ro);
			} else if ((command[0]=='r'||command[0]=='c')&&command[1]=='f') {
				command[0]='f';

				for (int j=no_of_circles-1; j>0; j--) {
					x[j]=x[j-1];
					y[j]=y[j-1];
					c[j].reset(x[j],y[j],ro);
				}

				x[0]=x[0]+2*ro;
				c[0].reset(x[0],y[0],ro);
			} else if ((command[0]=='r'||command[0]=='c')&&command[1]=='d') {
				command[0]='d';

				for (int j=no_of_circles-1; j>0; j--) {
					x[j]=x[j-1];
					y[j]=y[j-1];
					c[j].reset(x[j],y[j],ro);
				}

				x[0]=x[0]-2*ro;
				c[0].reset(x[0],y[0],ro);
			}
		} else {
			if (stage==3) {
				if ((x[0]>=100&&x[0]<=700)&&(y[0]==20||y[0]==780)) {
					touch=true;
				}

				if ((y[0]<=680&&y[0]>=120)&&(x[0]==30||x[0]==770)) {
					touch=true;
				}

				if (xxx==0) {
					button bb1(" ",20,600,10,400,"black");
					button bb2(" ",20,600,790,400,"black");
					button bb3(" ",560,30,400,15,"black");
					button bb4(" ",560,30,400,785,"black");
				}

				xxx++;
			}

			if (stage==1||stage==3) {
				double xo,yo;

				if ((x[0]-x[1]==20||x[0]-x[1]==-780)&&((x[0]>0))&&(x[0]<800)) {
					xo=x[0]+2*ro;
					yo=y[0];
				} else if ((x[0]-x[1]==-20||x[0]-x[1]==780)&&((x[0]<800)&&(x[0]>0))) {
					xo=x[0]-2*ro;
					yo=y[0];
				} else if ((x[0]-x[1]>0)&&x[0]>=800) {
					xo=x[0]-800+2*ro;
					yo=y[0];
				} else if ((x[0]-x[1]<0)&&x[0]<=0) {
					xo=x[0]+800-2*ro;
					yo=y[0];
				}

				if ((y[0]-y[1]==20||y[0]-y[1]==-780)&&((y[0]>0))&&(y[0]<800)) {
					yo=y[0]+2*ro;
					xo=x[0];
				} else if ((y[0]-y[1]==-20||y[0]-y[1]==780)&&((y[0]<800)&&(y[0]>0))) {
					yo=y[0]-2*ro;
					xo=x[0];
				} else if ((y[0]-y[1]>0)&&y[0]>=800) {
					yo=y[0]-800+2*ro;
					xo=x[0];
				} else if ((y[0]-y[1]<0)&&y[0]<=0) {
					yo=y[0]+800-2*ro;
					xo=x[0];
				}

				for (int j=no_of_circles-1; j>0; j--) {
					x[j]=x[j-1];
					y[j]=y[j-1];
					c[j].reset(x[j],y[j],ro);
				}

				x[0]=xo;
				y[0]=yo;

				if (x[0]==810)x[0]=10;

				if (x[0]==-10)x[0]=790;

				c[0].reset(x[0],y[0],ro);
			}

			if (stage==2) {
				if (xxx==0) {
					button bb1(" ",20,800,10,400,"black");
					button bb2(" ",20,800,790,400,"black");
					button bb3(" ",760,30,400,15,"black");
					button bb4(" ",760,30,400,785,"black");
				}

				xxx++;
				double xo,yo;

				if (x[0]-x[1]>0) {
					xo=x[0]+2*ro;
					yo=y[0];
				} else if (x[0]-x[1]<0) {
					xo=x[0]-2*ro;
					yo=y[0];
				}

				if (y[0]-y[1]>0) {
					yo=y[0]+2*ro;
					xo=x[0];
				} else if (y[0]-y[1]<0) {
					yo=y[0]-2*ro;
					xo=x[0];
				}

				for (int j=no_of_circles-1; j>0; j--) {
					x[j]=x[j-1];
					y[j]=y[j-1];
					c[j].reset(x[j],y[j],ro);
				}

				x[0]=xo;
				y[0]=yo;
				c[0].reset(x[0],y[0],ro);

				if (x[0]==10||x[0]==790) {
					touch=true;
				}

				if (y[0]==20||y[0]==780) {
					touch=true;
				}
			}
		}

		for (int s=1; s<no_of_circles; s++) {
			if (x[0]==x[s]&&y[0]==y[s]) {
				touch=true;
			}
		}

		wait(.01*(7-speed)*(7-speed));

		if (touch) break;
	}

	Rectangle plain(400,400,400,400);
	plain.setColor(COLOR("white"));
	plain.setFill();
	Text game_over(400,400,"OOOOps !!!!!!!!!!!!!!!!!!GAME OVER");
	game_over.imprint();
	Text score3(400,500,"Your score is ");
	Text score2(500,500,score);
	button b1("TRY AGAIN",150,40,700,40,"green");
	button b2("GO BACK ",150,40,700,450,"green");
	button b3("EXIT	",150,40,700,860,"green");

	while (true) {
		int next=getClick();

		if (b1.inside(next/65536,next%65536)) {
b1.hide();b2.hide();
b3.hide();			level_of_the_game(stage);
			break;
		}

		if (b2.inside(next/65536,next%65536)) {
b1.hide();b2.hide();
b3.hide();
			level_game();
			break;
		}

		if (b3.inside(next/65536,next%65536)) {
			closeCanvas();
			break;
		}
	}
}

void mainpage()
{
	initCanvas("main page",800,900);

	Rectangle ra(250,250,400,400);
	//ra.setFill(true);
	//ra.setColor(COLOR(0,0,255));

	Rectangle rb(250,250,300,300);
	//rb.setFill(true);
	//rb.setColor(COLOR(100,100,100));

	Rectangle p1(250,140,300,40);
	//r.reset(250,140,300,40);


	Text t1(250,140,"Classical GAME");

	Rectangle p2(250,190,300,40);



	Text t2(250,190,"level of the game");

	Rectangle p3(250,240,300,40);


	Text t3(250,240,"How to PLAY the GAME");

	Rectangle p4(250,290,300,40);

	Text t4(250,290,"About the GAME");

	Rectangle p5(250,340,300,40);

	Text t5(250,340,"about us");
	Text t6(250,70,"ThE SnAkE ");
	Rectangle p6(400,430,100,40);
	Text t7(400,430,"Quit");



		int next=getClick();
int u=next/65536;
int v=next%65536;
		if (u>=100&&u<=400&&v<=160&&v>=120) {
ra.hide();
rb.hide();
	p1.hide();
	p2.hide();
	p3.hide();
	p4.hide();
	p5.hide();
	p6.hide();
	t1.hide();
	t2.hide();
	t3.hide();
	t4.hide();
	t5.hide();
	t6.hide();
	t7.hide();


			level_game();

		}

		if (u>=100&&u<=400&&v<=210&&v>=170) {
				ra.hide();
	rb.hide();
	p1.hide();
	p2.hide();
	p3.hide();
	p4.hide();
	p5.hide();
	p6.hide();
	t1.hide();
	t2.hide();
	t3.hide();
	t4.hide();
	t5.hide();
	t6.hide();
	t7.hide();
			speed_of_game();

		}

		if (u>=100&&u<=400&&v<=260&&v>=220) {
				ra.hide();
	rb.hide();
	p1.hide();
	p2.hide();
	p3.hide();
	p4.hide();
	p5.hide();
	p6.hide();
	t1.hide();
	t2.hide();
	t3.hide();
	t4.hide();
	t5.hide();
	t6.hide();
	t7.hide();
			how_to_play();

		}

		if (u>=100&&u<=400&&v<=310&&v>=270) {
				ra.hide();
	rb.hide();
	p1.hide();
	p2.hide();
	p3.hide();
	p4.hide();
	p5.hide();
	p6.hide();
	t1.hide();
	t2.hide();
	t3.hide();
	t4.hide();
	t5.hide();
	t6.hide();
	t7.hide();
			about_the_game();

		}

		if (u>=100&&u<=400&&v<=360&&v>=320) {
            	ra.hide();
	rb.hide();
	p1.hide();
	p2.hide();
	p3.hide();
	p4.hide();
	p5.hide();
	p6.hide();
	t1.hide();
	t2.hide();
	t3.hide();
	t4.hide();
	t5.hide();
	t6.hide();
	t7.hide();
			about_us();

		}

		if (u>=100&&u<=400&&v<=450&&v>=410) {
				ra.hide();
	rb.hide();
	p1.hide();
	p2.hide();
	p3.hide();
	p4.hide();
	p5.hide();
	p6.hide();
	t1.hide();
	t2.hide();
	t3.hide();
	t4.hide();
	t5.hide();
	t6.hide();
	t7.hide();


		}

}

void kill()
{


	Rectangle ra(250,250,400,400);
	//ra.setFill(true);
	//ra.setColor(COLOR(0,0,255));

	Rectangle rb(250,250,300,300);
	//rb.setFill(true);
	//rb.setColor(COLOR(100,100,100));

	Rectangle p1(250,140,300,40);
	//r.reset(250,140,300,40);


	Text t1(250,140,"Classical GAME");

	Rectangle p2(250,190,300,40);



	Text t2(250,190,"level of the game");

	Rectangle p3(250,240,300,40);


	Text t3(250,240,"How to PLAY the GAME");

	Rectangle p4(250,290,300,40);

	Text t4(250,290,"About the GAME");

	Rectangle p5(250,340,300,40);

	Text t5(250,340,"about us");
	Text t6(250,70,"ThE SnAkE ");
	Rectangle p6(400,430,100,40);
	Text t7(400,430,"Quit");



		int next=getClick();
int u=next/65536;
int v=next%65536;
		if (u>=100&&u<=400&&v<=160&&v>=120) {
ra.hide();
rb.hide();
	p1.hide();
	p2.hide();
	p3.hide();
	p4.hide();
	p5.hide();
	p6.hide();
	t1.hide();
	t2.hide();
	t3.hide();
	t4.hide();
	t5.hide();
	t6.hide();
	t7.hide();


			level_game();

		}

		if (u>=100&&u<=400&&v<=210&&v>=170) {
				ra.hide();
	rb.hide();
	p1.hide();
	p2.hide();
	p3.hide();
	p4.hide();
	p5.hide();
	p6.hide();
	t1.hide();
	t2.hide();
	t3.hide();
	t4.hide();
	t5.hide();
	t6.hide();
	t7.hide();
			speed_of_game();

		}

		if (u>=100&&u<=400&&v<=260&&v>=220) {
				ra.hide();
	rb.hide();
	p1.hide();
	p2.hide();
	p3.hide();
	p4.hide();
	p5.hide();
	p6.hide();
	t1.hide();
	t2.hide();
	t3.hide();
	t4.hide();
	t5.hide();
	t6.hide();
	t7.hide();
			how_to_play();

		}

		if (u>=100&&u<=400&&v<=310&&v>=270) {
				ra.hide();
	rb.hide();
	p1.hide();
	p2.hide();
	p3.hide();
	p4.hide();
	p5.hide();
	p6.hide();
	t1.hide();
	t2.hide();
	t3.hide();
	t4.hide();
	t5.hide();
	t6.hide();
	t7.hide();
			about_the_game();

		}

		if (u>=100&&u<=400&&v<=360&&v>=320) {
            	ra.hide();
	rb.hide();
	p1.hide();
	p2.hide();
	p3.hide();
	p4.hide();
	p5.hide();
	p6.hide();
	t1.hide();
	t2.hide();
	t3.hide();
	t4.hide();
	t5.hide();
	t6.hide();
	t7.hide();
			about_us();

		}

		if (u>=100&&u<=400&&v<=450&&v>=410) {
				ra.hide();
	rb.hide();
	p1.hide();
	p2.hide();
	p3.hide();
	p4.hide();
	p5.hide();
	p6.hide();
	t1.hide();
	t2.hide();
	t3.hide();
	t4.hide();
	t5.hide();
	t6.hide();
	t7.hide();


		}

}
void level_game()
{

	//initCanvas("levels",500,500);

	Circle c(-7,-57,7);
	button b1("Level 1",100,40,250,100,"black");
	button b2("Level 2",100,40,250,175,"black");
	button b3("level 3",100,40,250,250,"black");
	button b7("MAIN MENU",160,40,250,470,"black");

	while (true) {
		int next=getClick();

		if (b1.inside(next/65536,next%65536)) {
		b1.hide();b3.hide();b2.hide();
b7.hide();
			level_of_the_game(1);
			break;
		}

		if (b2.inside(next/65536,next%65536)) {
b1.hide();b3.hide();b2.hide();b7.hide();
			level_of_the_game(2);
			break;
		}

		if (b3.inside(next/65536,next%65536)) {
			level_of_the_game(3);
			break;
		}
b1.hide();b3.hide();b2.hide();b7.hide();
		if (b7.inside(next/65536,next%65536)) {
			b1.hide();b3.hide();b2.hide();b7.hide();

			kill();
			break;
		}
	}
}
int main()
{
	char a[100];
	cout<<"hello welcome to ur snake game\n";
	cout<<"Ur name:";
	cin >>a;
	mainpage();
}
