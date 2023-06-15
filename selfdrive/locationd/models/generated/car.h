#pragma once
#include "rednose/helpers/common_ekf.h"
extern "C" {
void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_err_fun(double *nom_x, double *delta_x, double *out_7806729380221151220);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_5704254474892688384);
void car_H_mod_fun(double *state, double *out_4208275903993616188);
void car_f_fun(double *state, double dt, double *out_434195176901812415);
void car_F_fun(double *state, double dt, double *out_4166634264733628142);
void car_h_25(double *state, double *unused, double *out_5910888359297314153);
void car_H_25(double *state, double *unused, double *out_6947792830194027240);
void car_h_24(double *state, double *unused, double *out_2008521997787469843);
void car_H_24(double *state, double *unused, double *out_9120442429199526806);
void car_h_30(double *state, double *unused, double *out_5753701690946185008);
void car_H_30(double *state, double *unused, double *out_4429459871686778613);
void car_h_26(double *state, double *unused, double *out_3711073210756525843);
void car_H_26(double *state, double *unused, double *out_7757447924641468152);
void car_h_27(double *state, double *unused, double *out_6514204243973791670);
void car_H_27(double *state, double *unused, double *out_6604223183487203524);
void car_h_29(double *state, double *unused, double *out_8295090301481737596);
void car_H_29(double *state, double *unused, double *out_3919228527372386429);
void car_h_28(double *state, double *unused, double *out_8789733061586843804);
void car_H_28(double *state, double *unused, double *out_9001627544441917003);
void car_h_31(double *state, double *unused, double *out_2963162368941829192);
void car_H_31(double *state, double *unused, double *out_7131239822408116676);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}