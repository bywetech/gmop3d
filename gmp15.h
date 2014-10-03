

double ag_2t3_l, ag_2t3_r, ag_3t4_l, ag_3t4_r, ag_4t5_l,  ag_4t5_r, ag_5t6_l, ag_5t6_r;
double dlt_ag1, dlt_ag2, dlt_ag3, dlt_aglf, dlt_agrt;
double dlt_ln1, dlt_ln2, dlt_ln3;

double dt_pt1x, dt_pt1y, dt_pt1z;
double dt_pt2x, dt_pt2y, dt_pt2z;
double dt_pt3x, dt_pt3y, dt_pt3z;
double dlt_ln1, dlt_ln2, dlt_ln3;
double dlt_ln1ag, dlt_ln2ag, dlt_ln3ag;
	
double ag_h1_xy, rad_h1_xy;
double ag_tgt_h, rad_tgt_h;
	
double ag_lf_1, ag_lf_2, ag_rt_1, ag_rt_2, ag_ref_1, ag_ref_2, ag_ref_3, ag_tr1, ag_tr2;
	
double ag_ref_dt11, ag_ref_dt12, ag_ref_dt21, ag_ref_dt22, ag_ref_dt31, ag_ref_dt32;

double axr1, axr2, axr3, axr4, axr5, axr6;



double axag_xz2, axag_yz2, axag_xy2, rad_xz2, rad_yz2, rad_xy2;
double axag_xz3, axag_yz3, axag_xy3, rad_xz3, rad_yz3, rad_xy3;
double axag_xz4, axag_yz4, axag_xy4, rad_xz4, rad_yz4, rad_xy4;
double axag_xz5, axag_yz5, axag_xy5, rad_xz5, rad_yz5, rad_xy5;
double axag_xz6, axag_yz6, axag_xy6, rad_xz6, rad_yz6, rad_xy6;
double axag_xz7, axag_yz7, axag_xy7, rad_xz7, rad_yz7, rad_xy7;

double axag_rot1, axag_rot2, axag_rot3, axag_rot4, axag_rot5, axag_rot6, axag_rot7;



void gt_agrad(double, double, double *, double *);
void gt_dlt_1();

void gt_dlt_2(double, double, double);

void gt_r3(double, double, double, double *, double *, double *);
void gtptfull(double, double, double, double, double, double);



void gtpt_rx(double, double, double, double, double, double, double*, double*, double*, double);
		
void gtpt_ry(double, double, double, double, double, double, double*, double*, double*, double);
		
void gtpt_rz(double, double, double, double, double, double, double*, double*, double*, double);
	
void gt_axag_rot_1();	
	
	
	
	


void gt_agrad(double xy, double yz, double *ag_vh, double *rad)
{
	if(xy>0 &&  yz>0)
	{
		*ag_vh = atan(yz / xy ) * 180.0/M_PI;
		*rad = yz /sin(*ag_vh*M_PI/180.0); 
		
		
	} else
	if(xy<0 &&  yz>0)
	{
		*ag_vh = 90 + fabs(atan(xy / yz ) * 180.0/M_PI);
		*rad = fabs(xy /sin(*ag_vh*M_PI/180.0)); 
		
	} else
	if(xy<0 && yz<0)
	{
		*ag_vh = 180 + fabs(atan(yz / xy ) * 180.0/M_PI);
		*rad = fabs(yz /sin(*ag_vh*M_PI/180.0)); 
		
	} else
	if(xy>0 && yz<0)
	{
		
		*ag_vh = 270 + fabs(atan(xy / yz ) * 180.0/M_PI);
		*rad = fabs(xy /sin(*ag_vh*M_PI/180.0)); 
		
	} else
	if(xy==0 && yz>0)
	{
		*ag_vh = 90;
		*rad = yz;

	} else
	if(xy==0 && yz<0)
	{
		*ag_vh=270;
		*rad = fabs(yz);

	} else
	if(xy>0 && yz==0)
	{
		*ag_vh= 360;
		*rad=xy;
;
	} else
	if(xy<0 && yz==0)
	{
		*ag_vh= 180;
		*rad=fabs(xy);

	} 
	
	printf("xy=%f, yz=%f\n", xy, yz);
	printf("*ag_vh=%f, *rad=%f\n", *ag_vh, *rad);

	
}


void gt_dlt_1()
{

	
	dt_pt1x = posi2x;
	dt_pt1y = posi2y;
	dt_pt1z = posi2z;
	
	dt_pt2x = posi3x - posi2x;
	dt_pt2y = posi3y - posi2y;
	dt_pt2z = posi3z - posi2z;
	
	dt_pt3x = posi5x-posi3x;
	dt_pt3y = posi5y-posi3y;
	dt_pt3z = posi5z-posi3z;
	
	
	printf("dtx%f, dty%f,dtz%f\n", dt_pt1x, dt_pt1y, dt_pt1z);
	printf("dtx%f, dty%f,dtz%f\n", dt_pt2x, dt_pt2y, dt_pt2z);
	printf("dtx%f, dty%f,dtz%f\n", dt_pt3x, dt_pt3y, dt_pt3z);
	

	
	gt_agrad(dt_pt2z, dt_pt2x, &ag_ref_dt11, &dlt_ln1);
	gt_agrad(dt_pt3z, dt_pt3x, &ag_ref_dt21, &dlt_ln2);
	
	
	printf("dt_pt2x=%f, dt_pt2z=%f\n", dt_pt2x, dt_pt2z);
	printf("dt_pt3x=%f, dt_pt3z=%f\n", dt_pt3x, dt_pt3z);
	printf("ag_ref_dt11=%f, ag_ref_dt21=%f\n", ag_ref_dt11, ag_ref_dt21);

	

}


void gt_r3(double ag, double rad, double rad_t, double *r3, double *ag1, double *ag2)
{
	
	 double a1, b1, r1;
	 double a2, b2, r2;
	 
	a1 = (sin(ag * M_PI/180)) * rad;
	b1 = (cos(ag * M_PI/180)) * rad;
	
	r1=rad;
	*ag1=ag;
	
	a2 = a1;
	
	b2 = rad_t - b1;
	
	*ag2= atan2(a2,b2)*180/M_PI;
	
	r2 = a2 / sin(*ag2*M_PI/180);
	
	*r3 = r2;
	
	printf("ag=%f, rad=%f, r1=%f, a1=%f, *ag1=%f\n", ag, rad, r1, a1, *ag1);
	printf("a2=%f, b2=%f, *ag2=%f, rad_t=%f, r2=%f\n", a2, b2, *ag2, rad_t, r2);
	
	printf("r3=%f, ag1=%f, ag2=%f\n", *r3, *ag1, *ag2);
}
	

void gt_dlt_2(double cd_x, double cd_y, double cd_z)
{
	gt_axag_rot_1();
	gt_dlt_1();
	
	double rad_drl, ag_drl;
	

	
	double dlt_dyr_1x, dlt_dyr_1y, dlt_dyr_1z;
	double dlt_dyr_2x, dlt_dyr_2y, dlt_dyr_2z;
	double dlt_dyr_3x, dlt_dyr_3y, dlt_dyr_3z;
	
	double dlt_dyr_1r, dlt_dyr_2r, dlt_dyr_3r;
	printf("cd_x=%f, cd_y=%f, cd_z=%f\n", cd_x, cd_y, cd_z);
	
	
	gt_agrad(cd_x, cd_y, &ag_tgt_h, &rad_tgt_h);
	printf("ag_tgt_h=%f, rad_tgt_h=%f\n", ag_tgt_h, rad_tgt_h);
	
	gt_agrad(rad_tgt_h, cd_z, &ag_drl, &rad_drl);
	
	printf("ag_drl=%f, rad_drl=%f\n", ag_drl, rad_drl);
	
	
	ag_tr1 = axag_xz2 - ag_drl;
	
	gt_r3(ag_tr1, rad_xz2, rad_drl, &dlt_ln3, &ag_lf_1, &ag_rt_1);
	
	printf("rad_xz2=%f, axag_xz2=%f\n", rad_xz2, axag_xz2);

	dlt_ag1= acos((pow (dlt_ln2, 2)+ pow (dlt_ln3, 2) - pow(dlt_ln1,2))/(2*dlt_ln2*dlt_ln3))*180.0/M_PI;

	dlt_ag2= acos((pow (dlt_ln1, 2)+ pow (dlt_ln3, 2) - pow(dlt_ln2,2))/(2*dlt_ln1*dlt_ln3))*180.0/M_PI;
	
	dlt_ag3= acos((pow (dlt_ln1, 2)+ pow (dlt_ln2, 2) - pow(dlt_ln3,2))/(2*dlt_ln1*dlt_ln2))*180.0/M_PI;
	
	ag_ref_1 = 180 - (ag_lf_1 + ag_rt_1);
	ag_ref_2 = ag_ref_1 + dlt_ag2;
	ag_tr2 = 90 - axag_xz2;
	ag_ref_3 = ag_ref_2 - ag_tr2;
	
	printf("ag_ref_1=%f, ag_lf_1=%f, ag_rt_1=%f\n", ag_ref_1, ag_lf_1, ag_rt_1);
	printf("ag_ref_2=%f, agax_xz2=%f, ag_tr2=%f\n", ag_ref_2, axag_xz2, ag_tr2);
	printf("ag_ref_3=%f\n", ag_ref_3);
	
	printf("ln1=%f, ln2=%f, ln3=%f\n", dlt_ln1, dlt_ln2, dlt_ln3);
	printf("d_ag1=%f, d_ag2=%f, d_ag3=%f\n", dlt_ag1, dlt_ag2, dlt_ag3);
	
	
	gt_agrad(rad_tgt_h, posi5y, &ag_h1_xy, &rad_h1_xy);
	
	printf("ag_h1_xy=%f, rad_h1_xy=%f\n", ag_h1_xy, rad_h1_xy);
	

	axr1 = ag_tgt_h - ag_h1_xy;
	
	// minutes the first angle of initial, then rotate
	
	axr2 =180- ag_ref_dt11 - ag_ref_3;
	
	axr3 =180- ag_ref_dt12 - dlt_ag3;	
	
	printf("rt1=%f, rt2=%f, rt3=%f\n", axr1, axr2, axr3);
	
	path1(axr1, axr2, axr3, 0 ,0, 0);
	
}


 
 void gt_axag_rot_1()
{
	gt_agrad(posi2x, posi2z, &axag_xz2, &rad_xz2);
	gt_agrad(posi2y, posi2z, &axag_yz2, &rad_yz2);
	gt_agrad(posi2x, posi2y, &axag_xy2, &rad_xy2);
	
	gt_agrad(frame3x, frame3z, &axag_xz3, &rad_xz3);
	gt_agrad(frame3y, frame3z, &axag_yz3, &rad_yz3);
	gt_agrad(frame3x, frame3y, &axag_xy3, &rad_xy3);
	
	gt_agrad(frame4x, frame4z, &axag_xz4, &rad_xz4);
	gt_agrad(frame4y, frame4z, &axag_yz4, &rad_yz4);
	gt_agrad(frame4x, frame4y, &axag_xy4, &rad_xy4);
	
	gt_agrad(frame5x, frame5z, &axag_xz5, &rad_xz5);
	gt_agrad(frame5y, frame5z, &axag_yz5, &rad_yz5);
	gt_agrad(frame5x, frame5y, &axag_xy5, &rad_xy5);
	
	gt_agrad(frame6x, frame6z, &axag_xz6, &rad_xz6);
	gt_agrad(frame6y, frame6z, &axag_yz6, &rad_yz6);
	gt_agrad(frame6x, frame6y, &axag_xy6, &rad_xy6);
	
	gt_agrad(frame7x, frame7z, &axag_xz7, &rad_xz7);
	gt_agrad(frame7y, frame7z, &axag_yz7, &rad_yz7);
	gt_agrad(frame7x, frame7y, &axag_xy7, &rad_xy7);

}



void gtptfull(double ax1, double ax2, double ax3, double ax4, double ax5, double ax6)
{
	
	  
	  

	gt_r_pos();
	
	
	printf("*** Axil 6 rotate ***\n");
		gtpt_rz(rpos7x, rpos7y, rpos7z, rpos6x, rpos6y, rpos6z, &cod67x, &cod67y, &cod67z, ax6);
	printf("*** Axil 5 rotate ***\n");	
		gtpt_ry(cod67x, cod67y, cod67z, rpos5x, rpos5y, rpos5z, &cod57x, &cod57y, &cod57z, ax5);
		gtpt_ry(rpos6x, rpos6y, rpos6z, rpos5x, rpos5y, rpos5z, &cod56x, &cod56y, &cod56z, ax5);
	printf("*** Axil 4 rotate ***\n");	
		gtpt_rz(cod57x, cod57y, cod57z, rpos4x, rpos4y, rpos4z, &cod47x, &cod47y, &cod47z, ax4);
		gtpt_rz(cod56x, cod56y, cod56z, rpos4x, rpos4y, rpos4z, &cod46x, &cod46y, &cod46z, ax4);
		gtpt_rz(rpos6x, rpos6y, rpos6z, rpos5x, rpos5y, rpos5z, &cod45x, &cod45y, &cod45z, ax4);
	printf("*** Axil 3 rotate ***\n");	
		gtpt_ry(cod47x, cod47y, cod47z, rpos3x, rpos3y, rpos3z, &cod37x, &cod37y, &cod37z, ax3);
		gtpt_ry(cod46x, cod46y, cod46z, rpos3x, rpos3y, rpos3z, &cod36x, &cod36y, &cod36z, ax3);
		gtpt_ry(cod45x, cod45y, cod45z, rpos3x, rpos3y, rpos3z, &cod35x, &cod35y, &cod35z, ax3);
		gtpt_ry(rpos4x, rpos4y, rpos4z, rpos3x, rpos3y, rpos3z, &cod34x, &cod34y, &cod34z, ax3);
	printf("*** Axil 2 rotate ***\n");		
		gtpt_ry(cod37x, cod37y, cod37z, rpos2x, rpos2y, rpos2z, &cod27x, &cod27y, &cod27z, ax2);
		gtpt_ry(cod36x, cod36y, cod36z, rpos2x, rpos2y, rpos2z, &cod26x, &cod26y, &cod26z, ax2);
		gtpt_ry(cod35x, cod35y, cod35z, rpos2x, rpos2y, rpos2z, &cod25x, &cod25y, &cod25z, ax2);
		gtpt_ry(cod34x, cod34y, cod34z, rpos2x, rpos2y, rpos2z, &cod24x, &cod24y, &cod24z, ax2);
		gtpt_ry(rpos3x, rpos3y, rpos3z, rpos2x, rpos2y, rpos2z, &cod23x, &cod23y, &cod23z, ax2);
	printf("*** Axil 1 rotate ***\n");	
		gtpt_rz(cod27x, cod27y, cod27z, rpos1x, rpos1y, rpos1z, &cod17x, &cod17y, &cod17z, ax1);
		gtpt_rz(cod26x, cod26y, cod26z, rpos1x, rpos1y, rpos1z, &cod16x, &cod16y, &cod16z, ax1);
		gtpt_rz(cod25x, cod25y, cod25z, rpos1x, rpos1y, rpos1z, &cod15x, &cod15y, &cod15z, ax1);
		gtpt_rz(cod24x, cod24y, cod24z, rpos1x, rpos1y, rpos1z, &cod14x, &cod14y, &cod14z, ax1);
		gtpt_rz(cod23x, cod23y, cod23z, rpos1x, rpos1y, rpos1z, &cod13x, &cod13y, &cod13z, ax1);
		gtpt_rz(rpos2x, rpos2y, rpos2z, rpos1x, rpos1y, rpos1z, &cod12x, &cod12y, &cod12z, ax1);
		
		

}

