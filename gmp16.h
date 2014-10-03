FILE * md1;
FILE * mod1;
FILE *gtmod1;

double posi1x, posi1y, posi1z, rot1x, rot1y, rot1z;
double posi2x, posi2y, posi2z, rot2x, rot2y, rot2z;
double posi3x, posi3y, posi3z, rot3x, rot3y, rot3z;
double posi4x, posi4y, posi4z, rot4x, rot4y, rot4z;
double posi5x, posi5y, posi5z, rot5x, rot5y, rot5z;
double posi6x, posi6y, posi6z, rot6x, rot6y, rot6z;
double	posi7x, posi7y, posi7z, rot7x, rot7y, rot7z;

double rpos1x, rpos1y, rpos1z;
double rpos2x, rpos2y, rpos2z;
double rpos3x, rpos3y, rpos3z;
double rpos4x, rpos4y, rpos4z;
double rpos5x, rpos5y, rpos5z;
double rpos6x, rpos6y, rpos6z;
double rpos7x, rpos7y, rpos7z;



double framesize, fmsz, axdia, nz;

double frame1x, frame1y, frame1z;
double frame2x, frame2y, frame2z; 

double frame3x, frame3y, frame3z;
double frame4x, frame4y, frame4z; 
double frame5x, frame5y, frame5z;
double frame6x, frame6y, frame6z; 
double frame7x, frame7y, frame7z;


double cod12x, cod12y, cod12z;
double cod13x, cod13y, cod13z;
double cod14x, cod14y, cod14z;
double cod15x, cod15y, cod15z;
double cod16x, cod16y, cod16z;
double cod17x, cod17y, cod17z;


double cod23x, cod23y, cod23z;
double cod24x, cod24y, cod24z;
double cod25x, cod25y, cod25z;
double cod26x, cod26y, cod26z;
double cod27x, cod27y, cod27z;

double cod23x, cod23y, cod23z;
double cod24x, cod24y, cod24z;
double cod25x, cod25y, cod25z;
double cod26x, cod26y, cod26z;
double cod27x, cod27y, cod27z;

double cod34x, cod34y, cod34z;
double cod35x, cod35y, cod35z;
double cod36x, cod36y, cod36z;
double cod37x, cod37y, cod37z;


double cod45x, cod45y, cod45z;
double cod46x, cod46y, cod46z;
double cod47x, cod47y, cod47z;

double cod56x, cod56y, cod56z;
double cod57x, cod57y, cod57z;

double cod67x, cod67y, cod67z;

double axrot1, axrot2, axrot3, axrot4, axrot5, axrot6;

int h, v;

double cu_tx, cu_ty, cu_tz, cu_rx, cu_ry, cu_rz, cu_x, cu_y, cu_z;
double cy_tx, cy_ty, cy_tz, cy_rx, cy_ry, cy_rz, cy_x, cy_y, cy_z;
double sp_tx, sp_ty, sp_tz, sp_rx, sp_ry, sp_rz, sp_x, sp_y, sp_z;


double e_2xy, e_2z, e_2bsl, e_2drl, e_3xy, e_3z, e_3bsl, e_3drl;
double e_4xy, e_4z, e_4bsl, e_4drl, e_5xy, e_5z, e_5bsl, e_5drl;
double e_6xy, e_6z, e_6bsl, e_6drl, e_7xy, e_7z, e_7bsl, e_7drl;

double ex2xy, ex2z, ex2bsl, ex2drl, ex3xy, ex3z, ex3bsl, ex3drl;
double ex4xy, ex4z, ex4bsl, ex4drl, ex5xy, ex5z, ex5bsl, ex5drl;
double ex6xy, ex6z, ex6bsl, ex6drl, ex7xy, ex7z, ex7bsl, ex7drl;

double r_codx, r_cody, r_codz;

double mtx, mty, mtz, mcx, mcy, mcz, mrx, mry, mrz;
	


void gtpos(double, double, double, double *, double *, double *);
void gt_r_pos();
void dataqz_2();
void gtpath1(double, double, double, double, double, double);
void gt_mdpt1();

void gt_dlt_2(double, double, double);
void gtmotion();
void f_menu();
void f_ani();

void gtsfacfull();

void cal_scad();



 void dataqz_2(){
	

	
	// data axil 1	
	fmsz = 30;	nz = 0.0; axdia=200;
	posi1x=posi1y=posi1z=0;
	rot1x=0;rot1y=0;rot1z=0;
	frame1x=frame1y=frame1z=0;	


	// data axil 2
		
	posi2x=400;posi2y=200;posi2z=300;
	
	rot2x=90; rot2y=0; rot2z=0;
	frame2x=posi2x;
	frame2y=posi2y;
	frame2z=posi2z;
	


	// data axil 3
		
	posi3x=500; posi3y=350; posi3z = 1700;
	
	rot3x=90; rot3y=0; rot3z=0;
	frame3x = posi3x - posi2x;
	frame3y = posi3y - posi2y;
	frame3z = posi3z - posi2z;
	

	
	// data axil 4
	
	posi4x=670; posi4y=550; posi4z = 1380;

	rot4x=0; rot4y=0; rot4z=0;
	frame4x = posi4x - posi3x;
	frame4y = posi4y - posi3y;
	frame4z = posi4z - posi3z;
	

	// data axil 5
	
	posi5x=697; posi5y=595; posi5z = 2836;
	rot5x=90; rot5y=0; rot5z=0;
	frame5x = posi5x - posi4x;
	frame5y = posi5y - posi4y;
	frame5z = posi5z - posi4z;
	

	
	// data axil 6
	
	posi6x=600; posi6y=500; posi6z = 3100;

	rot6x=0; rot6y=0; rot6z=0;
	frame6x = posi6x - posi5x;
	frame6y = posi6y - posi5y;
	frame6z = posi6z - posi5z;
	

	
	// point 7 teminial
	
	posi7x=605, posi7y=509, posi7z=3160;
	rot7x=0, rot7y=0, rot7z=0;
	
	frame7x = posi7x - posi6x;
	frame7y = posi7y - posi6y;
	frame7z = posi7z - posi6z;



	
	
}

void gtrpos()
{
	gtpos(posi1x, posi1y, posi1z, &rpos1x, &rpos1y, &rpos1z);
	gtpos(posi2x, posi2y, posi2z, &rpos2x, &rpos2y, &rpos2z);
	gtpos(posi3x, posi3y, posi3z, &rpos3x, &rpos3y, &rpos3z);
	gtpos(posi4x, posi4y, posi4z, &rpos4x, &rpos4y, &rpos4z);
	gtpos(posi5x, posi5y, posi5z, &rpos5x, &rpos5y, &rpos5z);
	gtpos(posi6x, posi6y, posi6z, &rpos6x, &rpos6y, &rpos6z);
	gtpos(posi7x, posi7y, posi7z, &rpos7x, &rpos7y, &rpos7z);
	

}

void gtpos(double x, double y, double z, double *px, double *py, double *pz)
{
	
// The pointer must be first position

	*px = x;
	*py = y;
	*pz = z;
	printf("x=%f, y=%f, z=%f, rx=%f, ry=%f, rz=%f\n", x, y, z, *px, *py, *pz);

	
}


double axle1(double ornt1){
	
	 fprintf(md1, "// axil 1\n\n");
		fprintf(md1, "rotate([0,0,%f])\n", ornt1);
		fprintf(md1, "union(){\n");
		
		// Axil one
		

	fprintf(md1, "color([1,0,1], 0.5)\n translate([%f,%f,%f])\n rotate([%f,%f,%f])\n cylinder(r=200, h=20);\n ", 
		posi1x, posi1y, posi1z, rot1x, rot1y, rot1z);
		
		fprintf(md1, "color([1,0,0])\n union(){\n");		
	fprintf(md1, "translate([%f,%f,%f])\n cube([%f,%f,%f]);\n \
	translate([%f,%f,%f])\n cube([%f,%f,%f]);\n \
	translate([%f,%f,%f])\n cube([%f,%f,%f]);\n",   
		posi1x, posi1y, posi1z, posi2x, fmsz, fmsz, 
		posi2x, posi1y, posi1z, fmsz,  posi2y, fmsz, 
		posi2x, posi2y, posi1z, fmsz, fmsz, posi2z);
		fprintf(md1, "}\n\n");

}

double axle2(double ornt2)
{
	
	
		// rotate of axil 2
		
		  fprintf(md1, "// axil 2\n\n");	
	fprintf(md1, "translate([%f,%f,%f])\n", posi2x, posi2y, posi2z);		
	fprintf(md1, "rotate([0,%f,0])\n", ornt2);
		fprintf(md1, "union(){\n");
		
		// Axil two
		
	fprintf(md1, "color([1,0,1], 0.5)\n  rotate([%f,%f,%f])\n cylinder(r=200, h=20);\n", 
		 rot2x, rot2y, rot2z);
		
		fprintf(md1, "color([0,1,0])\n union(){\n");
		fprintf(md1, "translate([%f,%f,%f])\n cube([%f,%f,%f]);\n \
	translate([%f,%f,%f])\n cube([%f,%f,%f]);\n \
	translate([%f,%f,%f])\n cube([%f,%f,%f]);\n", 
			 nz, nz, nz, frame3x, fmsz, fmsz, 
			 frame3x, nz, nz, fmsz, frame3y, fmsz, 
			 frame3x, frame3y, nz, fmsz, fmsz, frame3z);	

		fprintf(md1, "}\n\n");
		

}


double axle3(double ornt3)
{
		
			// rotate of axil 3
			
				  fprintf(md1, "// axil 3\n\n");
		
	fprintf(md1, "translate([%f,%f,%f])\n", frame3x, frame3y, frame3z);
	
	fprintf(md1, "rotate([0,%f,0])\n", ornt3);		
		fprintf(md1, "union(){\n");
		


		
		// Axil three
		
	fprintf(md1, "color([1,0,1], 0.5)\n rotate([%f,%f,%f])\n cylinder(r=200, h=20);\n", 
		 rot3x, rot3y, rot3z);
	
	fprintf(md1, "color([0,0,1])\n union(){\n");
		fprintf(md1, "translate([%f,%f,%f])\n cube([%f,%f,%f]);\n \
	translate([%f,%f,%f])\n cube([%f,%f,%f]);\n \
	translate([%f,%f,%f])\n cube([%f,%f,%f]);\n", 
			 nz, nz, nz, fabs(frame4x), fmsz, fmsz, 
			 frame4x, nz, nz, fmsz, fabs(frame4y), fmsz, 
			 frame4x, frame4y, frame4z, fmsz, fmsz, fabs(frame4z));
		fprintf(md1, "}\n\n");
		

}


double axle4(double ornt4)
{
	// rotate of axil 4

	  fprintf(md1, "// axil 4\n\n");
		
	fprintf(md1, "translate([%f,%f,%f])\n", frame4x, frame4y, frame4z);
	
	fprintf(md1, "rotate([0,0,%f])\n", ornt4);		
		fprintf(md1, "union(){\n");
		
			 
		// Axil four
		
	fprintf(md1, "color([1,0,1], 0.5)\n rotate([%f,%f,%f])\n cylinder(r=200, h=20);\n", 
		 rot4x, rot4y, rot4z);
	
	fprintf(md1, "color([1,1,0])\n union(){\n");
		fprintf(md1, "translate([%f,%f,%f])\n cube([%f,%f,%f]);\n \
	translate([%f,%f,%f])\n cube([%f,%f,%f]);\n \
	translate([%f,%f,%f])\n cube([%f,%f,%f]);\n", 
			 nz, nz, nz, fabs(frame5x), fmsz, fmsz, 
			 frame5x, nz, nz, fmsz, fabs(frame5y), fmsz, 
			 frame5x, frame5y, nz, fmsz, fmsz, fabs(frame5z));
		fprintf(md1, "}\n\n");
		
		

}


double axle5(double ornt5)
{
	
					// rotate of axil 5

	  fprintf(md1, "// axil 5\n\n");		
	fprintf(md1, "translate([%f,%f,%f])\n", frame5x, frame5y, frame5z);
	
	fprintf(md1, "rotate([0,%f,0])\n", ornt5);		
		fprintf(md1, "union(){\n");
		
				 
		// Axil five
		
	fprintf(md1, "color([1,0,1], 0.5)\n rotate([%f,%f,%f])\n cylinder(r=200, h=20);\n", 
		 rot5x, rot5y, rot5z);
	
	fprintf(md1, "color([0,1,5])\n union(){\n");
		fprintf(md1, "translate([%f,%f,%f])\n cube([%f,%f,%f]);\n \
	translate([%f,%f,%f])\n cube([%f,%f,%f]);\n \
	translate([%f,%f,%f])\n cube([%f,%f,%f]);\n", 
			 frame6x, frame6y, nz, fabs(frame6x), fmsz, fmsz, 
			 nz, frame6y, nz, fmsz, fabs(frame6y), fmsz, 
			 frame6x, frame6y, nz, fmsz, fmsz, fabs(frame6z));
			 	fprintf(md1, "}\n\n");
			 
	
}

double axle6(double ornt6)
{

// rotate of axil 6

	  fprintf(md1, "// axil 6\n\n");		
	fprintf(md1, "translate([%f,%f,%f])\n", frame6x, frame6y, frame6z);
	
	fprintf(md1, "rotate([0,0,%f])\n", ornt6);		
		fprintf(md1, "union(){\n");
		
		
		
	// Axil six, this is the terminal points
		
	fprintf(md1, "color([1,0,1], 0.5)\n rotate([%f,%f,%f])\n cylinder(r=200, h=20);\n", 
		 rot6x, rot6y, rot6z);
	
	fprintf(md1, "color([0,0,1])\n union(){\n");
		fprintf(md1, "translate([%f,%f,%f])\n cube([%f,%f,%f]);\n \
	translate([%f,%f,%f])\n cube([%f,%f,%f]);\n \
	translate([%f,%f,%f])\n cube([%f,%f,%f]);\n", 
			 nz, nz, nz, axdia, fmsz, fmsz, 
			 frame7x, nz, nz, fmsz, frame7y, fmsz, 
			 frame7x, frame7y, nz, fmsz, fmsz, frame7z); 
 	fprintf(md1, "}\n\n");
 	

	fprintf(md1, "}}}}}}\n");
	
}


double path1(double n1, double n2, double n3, double n4, double n5, double n6)
{
		
	
	axle1(n1);
	axle2(n2);
	axle3(n3);
	axle4(n4);
	axle5(n5);
	axle6(n6);	
					
	     
  
 
}


void gt_r_pos()
{
	gtpos(posi1x, posi1y, posi1z, &rpos1x, &rpos1y, &rpos1z);
	gtpos(posi2x, posi2y, posi2z, &rpos2x, &rpos2y, &rpos2z);
	gtpos(posi3x, posi3y, posi3z, &rpos3x, &rpos3y, &rpos3z);
	gtpos(posi4x, posi4y, posi4z, &rpos4x, &rpos4y, &rpos4z);
	gtpos(posi5x, posi5y, posi5z, &rpos5x, &rpos5y, &rpos5z);
	gtpos(posi6x, posi6y, posi6z, &rpos6x, &rpos6y, &rpos6z);
	gtpos(posi7x, posi7y, posi7z, &rpos7x, &rpos7y, &rpos7z);
	

}






void gtmotion()
{
	
	  double d_rx, d_ry, d_rz, d_tx, d_ty, d_tz, d_cx, d_cy, d_cz;

	mod1 = fopen("path1.dat", "w");
	

	char s_rx[100], s_ry[100], s_rz[100], s_tx[100], s_ty[100], s_tz[100], s_cx[100], s_cy[100], s_cz[100];
	
	printf("Gmop3d for get the motion path.\n");
	printf("1. cube, input the number only, individual with ' ' 'space' sign.\n");

	printf("translate([x, y, z]) for the position in the coordinate system.\n");
	printf("Enter the x, y, z only and divided by ',' colon sign.\n");
	
	scanf("%s %s %s", &s_tx, &s_ty, &s_tz);
	
	d_tx=atof(s_tx); 
	d_ty=atof(s_ty); 
	d_tz=atof(s_tz);
	
	printf("rotate([x, y, z]) for rotation of object path.\n");
	
	scanf("%s %s %s", &s_rx, &s_ry, &s_rz);
	
	d_rx=atof(s_rx); 
	d_ry=atof(s_ry); 
	d_rz=atof(s_rz);
	
	printf("cube([x, y, z]) for the size of the cube object motion path.\n");
	scanf("%s %s %s", &s_cx, &s_cy, &s_cz);
	
	d_cx=atof(s_cx); 
	d_cy=atof(s_cy); 
	d_cz=atof(s_cz);
	
	printf("	%f 	%f 	%f\n", d_tx, d_ty, d_tz);
	printf("	%f 	%f	%f\n", d_rx, d_ry, d_rz);
	printf("	%f	%f	%f\n", d_cx, d_cy, d_cz);
	
	
	fprintf(mod1, "	%f	%f	%f\n", d_tx, d_ty, d_tz);
	fprintf(mod1, "	%f	%f	%f\n", d_rx, d_ry, d_rz);
	fprintf(mod1, "	%f	%f	%f\n", d_cx, d_cy, d_cz);
	
	fclose(mod1);
	
}

void gt_mdpt1()
{
	gtmod1 = fopen("path1.dat", "r");
	
	
	char s_tx[100], s_ty[100], s_tz[100],  s_rx[100], s_ry[100], s_rz[100], s_cx[100], s_cy[100], s_cz[100];
	rewind(gtmod1);
	fscanf(gtmod1, "%s %s %s \
	 %s %s %s \
	 %s %s %s", s_tx, s_ty, s_tz, s_rx, s_ry, s_rz, s_cx, s_cy, s_cz);
	 
	 fclose(gtmod1);
	 
	    mtx=atof(s_tx); 
	mty=atof(s_ty); 
	mtz=atof(s_tz);
		mrx=atof(s_rx); 
	mry=atof(s_ry); 
	mrz=atof(s_rz);
		mcx=atof(s_cx); 
	mcy=atof(s_cy); 
	mcz=atof(s_cz);
	
	printf("%f %f	%f\n", mtx, mty, mtz);
	printf("%f %f	%f\n", mrx, mry, mrz);
	printf("%f %f	%f\n", mcx, mcy, mcz);
	
	
	
 }
 
void cal_scad()
{
	
	     pid_t pid;
	     

     if ((pid = fork()) < 0)
        perror("fork error");
     else if (pid == 0) {
       execl("/usr/local/bin/openscad", "./1.scad");
          
     }
  }
	



void f_menu()
{
  for(;;)
  {

  printf("\n\tgMOP3D MOtion Path with 3D animation\n\n");
  printf("Manipulator or axle base Robotics path model builder system.\n");
  printf("Simulation with openSCAD, but you must build path model again.\n");
  printf("Robot model with 6 axle, robot model changed by source code only.\n");
  printf("Path only support cube only, build path by your self by instructions.\n");
  printf("1. Build path model as build openSCAD model.\n");
  printf("2. Start animation of path model.\n");
  printf("99. Escape the Program and Save parameters.\n");
  printf("->");

  int c;
  char s_c[10];
  scanf("%s", &s_c);
  c = atoi(s_c);
    
    switch (c)
      {
              
	case 99: printf("Thanks for your use GMOP3D, and see you next time!\n");
	exit(0);

	case 1: gtmotion(); break;
	case 2: f_ani(); break;

  default: printf("\nError input! Please enter integer between 1 or 99 only.\n");
  break;
       
      }
  }
} 


void f_ani()
{
	md1 = fopen("1.scad", "w");
		
	// part one , got motion path model, robot model.
	
	cal_scad();
	dataqz_2();
	gtrpos();
	gt_mdpt1();
	
	gtsfacfull();
	
	
	
}


