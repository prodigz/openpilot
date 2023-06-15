#pragma once
#include "rednose/helpers/common_ekf.h"
extern "C" {
void live_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_9(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_12(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_35(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_32(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_33(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_H(double *in_vec, double *out_3184951436562767646);
void live_err_fun(double *nom_x, double *delta_x, double *out_7323533020603109004);
void live_inv_err_fun(double *nom_x, double *true_x, double *out_602826505350458911);
void live_H_mod_fun(double *state, double *out_7234055416017641464);
void live_f_fun(double *state, double dt, double *out_9030444261325526316);
void live_F_fun(double *state, double dt, double *out_7927715977959496876);
void live_h_4(double *state, double *unused, double *out_3637205304344111796);
void live_H_4(double *state, double *unused, double *out_3199237687935458826);
void live_h_9(double *state, double *unused, double *out_6939023978727812761);
void live_H_9(double *state, double *unused, double *out_2958048041305868181);
void live_h_10(double *state, double *unused, double *out_5134952168813292064);
void live_H_10(double *state, double *unused, double *out_2518434904635089190);
void live_h_12(double *state, double *unused, double *out_3209066940974086290);
void live_H_12(double *state, double *unused, double *out_1820218720096502969);
void live_h_35(double *state, double *unused, double *out_246045669141529389);
void live_H_35(double *state, double *unused, double *out_167424369437148550);
void live_h_32(double *state, double *unused, double *out_4754195077562618053);
void live_H_32(double *state, double *unused, double *out_6747440134256967806);
void live_h_13(double *state, double *unused, double *out_4247384275599747322);
void live_H_13(double *state, double *unused, double *out_1067669662797967462);
void live_h_14(double *state, double *unused, double *out_6939023978727812761);
void live_H_14(double *state, double *unused, double *out_2958048041305868181);
void live_h_33(double *state, double *unused, double *out_4679478756135752985);
void live_H_33(double *state, double *unused, double *out_3317981374076006154);
void live_predict(double *in_x, double *in_P, double *in_Q, double dt);
}