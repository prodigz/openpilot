#pragma once
#include "rednose/helpers/common_ekf.h"
extern "C" {
void gnss_update_6(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_20(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_7(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_21(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_err_fun(double *nom_x, double *delta_x, double *out_8031618320293225418);
void gnss_inv_err_fun(double *nom_x, double *true_x, double *out_338273384091461970);
void gnss_H_mod_fun(double *state, double *out_4694345153022137407);
void gnss_f_fun(double *state, double dt, double *out_3653497788380929555);
void gnss_F_fun(double *state, double dt, double *out_2199281361334248195);
void gnss_h_6(double *state, double *sat_pos, double *out_2825146410579927360);
void gnss_H_6(double *state, double *sat_pos, double *out_4850413402897355274);
void gnss_h_20(double *state, double *sat_pos, double *out_149741099389073143);
void gnss_H_20(double *state, double *sat_pos, double *out_5139884667526395233);
void gnss_h_7(double *state, double *sat_pos_vel, double *out_6142067295876116682);
void gnss_H_7(double *state, double *sat_pos_vel, double *out_682836583427487555);
void gnss_h_21(double *state, double *sat_pos_vel, double *out_6142067295876116682);
void gnss_H_21(double *state, double *sat_pos_vel, double *out_682836583427487555);
void gnss_predict(double *in_x, double *in_P, double *in_Q, double dt);
}