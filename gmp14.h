
	

double cox_3, coy_3, coz_3;


	


void gtdrli(double, double, double, double *, double *, double *, double *);

void rt(double, double, double, double *, double *);

void gtpt(double, double, double, double, double, double, double *, double *,  double *, double, double);

void gt_fullrot(double ,double *);

void gt_agany(double , double  , double *, double *, double, double *);

void gtpt_rx(double, double, double, double, double, double, double*, double*, double*, double);
		
void gtpt_ry(double, double, double, double, double, double, double*, double*, double*, double);
		
void gtpt_rz(double, double, double, double, double, double, double*, double*, double*, double);
		

void gt_rot2(double, double, double, double, double, double, double, double, double);

void gtsfac1_2(double, double, double, double, double, double, double, double, double, double, double);

void gtsfac3_4(double, double, double, double, double, double, double, double, double, double, double);

void gtsfac5(double, double, double, double, double, double, double, double, double, double, double);

void gtsfacfull();



void gtdrli(double x, double y, double z, double *ag_xy, double *ag_z, double *bs_l, double *dr_l)
{
	

		
	
	if(x>0 &&  y>0)
	{
		*ag_xy = atan(y / x ) * 180.0/M_PI;
		*bs_l = y /sin(*ag_xy*M_PI/180.0); 
	} else
	if(x<0 &&  y>0)
	{
		*ag_xy = 180 - fabs(atan(y / x ) * 180.0/M_PI);
		*bs_l = y /sin(*ag_xy*M_PI/180.0); 
	} else
	if(x<0 && y<0)
	{
		*ag_xy = 180 + fabs(atan(y / x ) * 180.0/M_PI);
		*bs_l = fabs(y / sin(*ag_xy*M_PI/180.0)); 
	} else
	if(x>0 && y <0)
	{
		*ag_xy = 270 + fabs(atan(y / x ) * 180.0/M_PI);
		*bs_l = fabs(y / sin(*ag_xy*M_PI/180.0)); 
	} else
	if(x==0 && y>0)
	{
		*ag_xy = 90;
		*bs_l = y;
	} else
	if(x==0 && y<0)
	{
		*ag_xy=270;
		*bs_l = fabs(y);
	} else
	if(x>0 && y==0)
	{
		*ag_xy= 360;
		*bs_l=x;
	} else
	if(x<0 && y==0)
	{
		*ag_xy= 180;
		*bs_l=fabs(x);
	} 
	
	
	
	if(z==0)
	{
	*ag_z = fabs(atan(z / *bs_l)*180.0/M_PI);
	*dr_l = *bs_l;
	} else
	{
		
	*ag_z = fabs(atan(z / *bs_l)*180.0/M_PI);
	*dr_l = fabs(z/sin(*ag_z * M_PI/180.0));
	}


	
}	





void rt(double rtxyz, double ptx, double ptyz, double *pt_x, double *pt_yz)
{
	
	double lin;
	
	lin = sqrt(pow(ptx, 2) + pow(ptyz, 2));
	


	if((rtxyz>0) && (rtxyz<90))
	{
	*pt_x = lin * cos(rtxyz*M_PI/180.0); 
	*pt_yz = lin * sin(rtxyz*M_PI/180.0);
		
	} 	else
	if((rtxyz>90) && (rtxyz<180))
	{
		rtxyz=rtxyz-90;
		
	*pt_x = -fabs(lin * sin(rtxyz*M_PI/180.0)); 
	*pt_yz =  fabs(lin * cos(rtxyz*M_PI/180.0));

	} else 
	if((rtxyz>180) && (rtxyz<270))
	{
		rtxyz=rtxyz-180;
	*pt_x = -fabs(lin * cos(rtxyz*M_PI/180.0)); 
	*pt_yz = -fabs(lin * sin(rtxyz*M_PI/180.0));

	} else
	if((rtxyz>270) && (rtxyz<360))
	{
		rtxyz=rtxyz-270;
	*pt_x =  fabs(lin * sin(rtxyz*M_PI/180.0)); 
	*pt_yz = -fabs(lin * cos(rtxyz*M_PI/180.0));

	
	} else
	if(rtxyz==90)
	{
		*pt_x=0;
		*pt_yz=lin;

		
	} else
	if(rtxyz==180)
	{
		*pt_x=-lin;
		*pt_yz=0;

	} else
	if(rtxyz==270)
	{
		*pt_x=0;
		*pt_yz=-lin;

	} else
	if(rtxyz==0 || rtxyz==360)
	{
		*pt_x=lin;
		*pt_yz=0;

	}
	
	
	
	
}







void gtpt(double x1, double y1, double z1, double x2, double y2, double z2, 
			double *xr, double *yr, double *zr, double vh, double fnr)
			
{
	
	
	
	double brrt_x, brrt_y, brrt_z;
	double agxy, agz, bsl, drl;
	double rot_x, rot_y, rot_z;
	double afrt_x, afrt_y, afrt_z;
	double ag_a, frt;
	
	double ag_vh, bsl_vh;

	
	
	if(vh==0)
	{

	brrt_x = x1 - x2;
	brrt_y = y1 - y2;
	brrt_z = z1 - z2;
	
	
	
	
	
	gt_agany(brrt_x, brrt_y, &ag_vh, &bsl_vh, fnr, &ag_a);
	
		
			gt_fullrot(ag_a,&frt);
			
		
		rt(frt, brrt_x, brrt_y, &afrt_x, &afrt_y);
		
	afrt_z = brrt_z;
	
	*xr = x1 + (afrt_x - brrt_x);
	*yr = y1 + (afrt_y - brrt_y);
	*zr = z1 + (afrt_z - brrt_z);
	} else
	if(vh==1)
	{
		
	brrt_x = x1 - x2;
	brrt_y = y1 - y2;
	brrt_z = z1 - z2;
	
	
	
	
	 gt_agany(brrt_y, brrt_z, &ag_vh, &bsl_vh, fnr, &ag_a);
	
	 		
		gt_fullrot(ag_a, &frt);	
		
	rt(frt, brrt_y, brrt_z, &afrt_y, &afrt_z);
		
	afrt_x = brrt_x;
	
	*xr = x1 + (afrt_x - brrt_x);
	*yr = y1 + (afrt_y - brrt_y);
	*zr = z1 + (afrt_z - brrt_z);


	} else
	
	{
		printf("rotate Error!\n");
	}
	


	
	

}

void gtpt_rz(double x1, double y1, double z1, double x2, double y2, double z2, 
			double *xr, double *yr, double *zr, double fnr)
			
{
	
	
	
	double brrt_x, brrt_y, brrt_z;
	double agxy, agz, bsl, drl;
	double rot_x, rot_y, rot_z;
	double afrt_x, afrt_y, afrt_z;
	double ag_a, frt;
	
	double ag_vh, bsl_vh;

	double ag_1, ag_2;
	
	brrt_x = x1 - x2;
	brrt_y = y1 - y2;
	brrt_z = z1 - z2;
	
	
	gt_fullrot(fnr, &ag_1);
	
	
	gt_agany(brrt_x, brrt_y, &ag_vh, &bsl_vh, ag_1, &ag_a);
	
		
			gt_fullrot(ag_a,&frt);
			
		
		rt(frt, brrt_x, brrt_y, &afrt_x, &afrt_y);
		
	afrt_z = brrt_z;
	
	*xr = x1 + (afrt_x - brrt_x);
	*yr = y1 + (afrt_y - brrt_y);
	*zr = z1 + (afrt_z - brrt_z);
	
	
	printf("%f,%f,%f\n", *xr, *yr, *zr);
}




void gtpt_ry(double x1, double y1, double z1, double x2, double y2, double z2, 
			double *xr, double *yr, double *zr, double fnr)
			
{
	
	
	
	double brrt_x, brrt_y, brrt_z;
	double agxy, agz, bsl, drl;
	double rot_x, rot_y, rot_z;
	double afrt_x, afrt_y, afrt_z;
	double ag_a, frt;
	
	double ag_vh, bsl_vh;

		double ag_1, ag_2, ag_11, ag_12;
	
	brrt_x = x1 - x2;
	brrt_y = y1 - y2;
	brrt_z = z1 - z2;
	
	

	
		printf("br_x=%f, br_y=%f, br_z=%f\n", brrt_x, brrt_y, brrt_z);
	
	gt_fullrot(fnr, &ag_1);
	
	ag_2 = 360-ag_1;
	
	gt_agany(brrt_x, brrt_z, &ag_vh, &bsl_vh, ag_2, &ag_a);
	
		
			gt_fullrot(ag_a,&frt);
			
		
		rt(frt, brrt_x, brrt_z, &afrt_x, &afrt_z);
		
	afrt_y = brrt_y;
	
	*xr = x1 + (afrt_x - brrt_x);
	*yr = y1 + (afrt_y - brrt_y);
	*zr = z1 + (afrt_z - brrt_z);
	
	printf("%f,%f,%f\n", *xr, *yr, *zr);

}


void gtpt_rx(double x1, double y1, double z1, double x2, double y2, double z2, 
			double *xr, double *yr, double *zr, double fnr)
			
{
	
	
	
	double brrt_x, brrt_y, brrt_z;
	double agxy, agz, bsl, drl;
	double rot_x, rot_y, rot_z;
	double afrt_x, afrt_y, afrt_z;
	double ag_a, frt;
	
	double ag_vh, bsl_vh;
	double ag_1;
	
	
	brrt_x = x1 - x2;
	brrt_y = y1 - y2;
	brrt_z = z1 - z2;
	
	
	
	gt_fullrot(fnr, &ag_1);
	
	gt_agany(brrt_y, brrt_z, &ag_vh, &bsl_vh, ag_1, &ag_a);
	
		
			gt_fullrot(ag_a,&frt);
			
		
		rt(frt, brrt_y, brrt_z, &afrt_y, &afrt_z);
		
	afrt_x = brrt_x;
	
	*xr = x1 + (afrt_x - brrt_x);
	*yr = y1 + (afrt_y - brrt_y);
	*zr = z1 + (afrt_z - brrt_z);
	
	printf("%f,%f,%f\n", *xr, *yr, *zr);

}




void gt_fullrot(double a, double *f)
{
	int b, c;
	b = 360;
	
	if((a>=0) && (a<=360))
	{
		*f = a;
	} else
	if(a>360)
	{
		c = a / b;
		
		*f = a-(c*b);
	} else
	if(a<0)
	{
		c = a/b;
		*f = b+(a-(c*b));
	}
	
	
}


void gt_agany(double xy, double yz, double *ag_vh, double *bsl_vh, double fr, double *aga)
{
	if(xy>0 &&  yz>0)
	{
		*ag_vh = atan(yz / xy ) * 180.0/M_PI;
		
		*bsl_vh = yz /sin(*ag_vh*M_PI/180.0); 
		*aga = *ag_vh + fr;
		
	} else
	if(xy<0 &&  yz>0)
	{
		*ag_vh = 90 + fabs(atan(xy / yz ) * 180.0/M_PI);
		
		*bsl_vh = fabs(xy /sin(*ag_vh*M_PI/180.0)); 
		*aga = *ag_vh + fr;
	} else
	if(xy<0 && yz<0)
	{
		*ag_vh = 180 + fabs(atan(yz / xy) * 180.0/M_PI);
		
		*bsl_vh = fabs(yz /sin(*ag_vh*M_PI/180.0)); 
		*aga = *ag_vh + fr;
	} else
	if(xy>0 && yz<0)
	{
		
		*ag_vh = 270 + fabs(atan(xy / yz) * 180.0/M_PI);	
		*bsl_vh = fabs(xy /sin(*ag_vh*M_PI/180.0)); 
		*aga = *ag_vh + fr;
		
	} else
	if(xy==0 && yz>0)
	{
		*ag_vh = 90;
		*bsl_vh = yz;
		*aga = *ag_vh + fr;
	} else
	if(xy==0 && yz<0)
	{
		*ag_vh=270;
		*bsl_vh = fabs(yz);
		*aga = *ag_vh + fr;
	} else
	if(xy>0 && yz==0)
	{
		*ag_vh= 360;
		*bsl_vh=xy;
		*aga = *ag_vh + fr;
	} else
	if(xy<0 && yz==0)
	{
		*ag_vh= 180;
		*bsl_vh=fabs(xy);
		*aga = *ag_vh + fr;
	} 
	
	printf("xy=%f, yz=%f, fr=%f\n", xy, yz, fr);
	printf("*ag_vh=%f, *bsl_vh=%f, *aga=%f\n", *ag_vh, *bsl_vh, *aga);

	
}




 void gt_rot2(double tx, double ty, double tz, double cx, double cy, double cz, 
					double rx, double ry, double rz)
{
	
	double cox_1, coy_1, coz_1, cox_2, coy_2, coz_2;
	
	double fx, fy, fz;
	
	fx = tx+cx;
	fy = ty+cy;
	fz = tz+cz;

	gtpt_rx(fx, fy, fz, tx, ty, tz, &cox_1, &coy_1, &coz_1, rx);
	gtpt_ry(cox_1, coy_1, coz_1, tx, ty, tz, &cox_2, &coy_2, &coz_2, ry);
	gtpt_rz(cox_2, coy_2, coz_2, tx, ty, tz, &cox_3, &coy_3, &coz_3, rz);	
	
	fprintf(md1, "\n\n");
	fprintf(md1, "color([0, 0, 1], 0.5)\n");
	fprintf(md1, "translate([%f, %f, %f])\n", mtx, mty, mtz);
	fprintf(md1, "rotate([%f, %f, %f])\n", mrx, mry, mrz);
	fprintf(md1, "cube([%f, %f, %f]);\n\n", mcx, mcy, mcz);
	
	fprintf(md1, "module cod_show(x, y, z){\n");
	fprintf(md1, "cube([x, y, 1]);\n");
	fprintf(md1, "cube([1, y, z]);\n");
	fprintf(md1, "translate([0,y,0])\n");
	fprintf(md1, "cube([x,1,z]);}\n");
	fprintf(md1, "color([1,0,0], 0.2)\n");
	fprintf(md1, "cod_show(%f,%f,%f);\n", cox_3, coy_3, coz_3);
	
		
	gt_dlt_2(cox_3, coy_3, coz_3);
	

}


void gtsfac1_2(double ts_x,  double ts_y, double ts_z, double rt_x, double rt_y, double rt_z, 
		double cu_x, double cu_y, double cu_z, double prcn_a, double prcn_b)
{
	
	double x, z;
	
	for(x=0; x<=cu_x; x=x+prcn_a)
	{
		for(z=0; z<=cu_z; z=z+prcn_b)
		{
		gt_rot2(ts_x, ts_y, ts_z, x, cu_y, z, rt_x, rt_y, rt_z);
		
	fflush(md1);
    rewind(md1);
    
  
	usleep(1000000);
		}
	}
	
	
	
}

void gtsfac3_4(double ts_x,  double ts_y, double ts_z, double rt_x, double rt_y, double rt_z, 
		double cu_x, double cu_y, double cu_z, double prcn_a, double prcn_b)
{
	
	double y, z;
	
	for(y=0; y<=cu_y; y=y+prcn_a)
	{
		for(z=0; z<=cu_z; z=z+prcn_b)
		{
		gt_rot2(ts_x, ts_y, ts_z, cu_x, y, z, rt_x, rt_y, rt_z);
		
    fflush(md1);
    rewind(md1);
    
	usleep(1000000);
		}
	}
	
	
	
}


void gtsfac5(double ts_x,  double ts_y, double ts_z, double rt_x, double rt_y, double rt_z, 
		double cu_x, double cu_y, double cu_z, double prcn_a, double prcn_b)
{
	
	double x, y;
	
	for(x=0; x<=cu_x; x=x+prcn_a)
	{
		for(y=0; y<=cu_y; y=y+prcn_b)
		{
		gt_rot2(ts_x, ts_y, ts_z, x, y, cu_z, rt_x, rt_y, rt_z);
		
	fflush(md1);
    rewind(md1);

    
	usleep(1000000);
		}
	}
	
	
	
}



void gtsfacfull()
{
	
	// face 1, xz, y = 0; front view;
	
	gtsfac1_2(mtx, mty, mtz, mrx, mry, mrz, mcx, 0, mcz, 10, 10);
	
	// face 2, xz, y = y; back view;
	
	gtsfac1_2(mtx, mty, mtz, mrx, mry, mrz, mcx, mcy, mcz, 10, 10);
	
	// face 3, yz, x = 0; left view;
	
	gtsfac3_4(mtx, mty, mtz, mrx, mry, mrz, 0, mcy, mcz, 10, 10);
	
	// face 4, yz, x = x; right view;
	
	gtsfac3_4(mtx, mty, mtz, mrx, mry, mrz, mcx, mcy, mcz, 10, 10);
	
	// face 5, xy, z = z; top view;
	
	gtsfac5(mtx, mty, mtz, mrx, mry, mrz, mcx, mcy, mcz, 10, 10);
	
	
}


