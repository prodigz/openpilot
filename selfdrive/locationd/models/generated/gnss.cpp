#include "gnss.h"

namespace {
#define DIM 11
#define EDIM 11
#define MEDIM 11
typedef void (*Hfun)(double *, double *, double *);
const static double MAHA_THRESH_6 = 3.8414588206941227;
const static double MAHA_THRESH_20 = 3.8414588206941227;
const static double MAHA_THRESH_7 = 3.8414588206941227;
const static double MAHA_THRESH_21 = 3.8414588206941227;

/******************************************************************************
 *                      Code generated with SymPy 1.11.1                      *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_8031618320293225418) {
   out_8031618320293225418[0] = delta_x[0] + nom_x[0];
   out_8031618320293225418[1] = delta_x[1] + nom_x[1];
   out_8031618320293225418[2] = delta_x[2] + nom_x[2];
   out_8031618320293225418[3] = delta_x[3] + nom_x[3];
   out_8031618320293225418[4] = delta_x[4] + nom_x[4];
   out_8031618320293225418[5] = delta_x[5] + nom_x[5];
   out_8031618320293225418[6] = delta_x[6] + nom_x[6];
   out_8031618320293225418[7] = delta_x[7] + nom_x[7];
   out_8031618320293225418[8] = delta_x[8] + nom_x[8];
   out_8031618320293225418[9] = delta_x[9] + nom_x[9];
   out_8031618320293225418[10] = delta_x[10] + nom_x[10];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_338273384091461970) {
   out_338273384091461970[0] = -nom_x[0] + true_x[0];
   out_338273384091461970[1] = -nom_x[1] + true_x[1];
   out_338273384091461970[2] = -nom_x[2] + true_x[2];
   out_338273384091461970[3] = -nom_x[3] + true_x[3];
   out_338273384091461970[4] = -nom_x[4] + true_x[4];
   out_338273384091461970[5] = -nom_x[5] + true_x[5];
   out_338273384091461970[6] = -nom_x[6] + true_x[6];
   out_338273384091461970[7] = -nom_x[7] + true_x[7];
   out_338273384091461970[8] = -nom_x[8] + true_x[8];
   out_338273384091461970[9] = -nom_x[9] + true_x[9];
   out_338273384091461970[10] = -nom_x[10] + true_x[10];
}
void H_mod_fun(double *state, double *out_4694345153022137407) {
   out_4694345153022137407[0] = 1.0;
   out_4694345153022137407[1] = 0;
   out_4694345153022137407[2] = 0;
   out_4694345153022137407[3] = 0;
   out_4694345153022137407[4] = 0;
   out_4694345153022137407[5] = 0;
   out_4694345153022137407[6] = 0;
   out_4694345153022137407[7] = 0;
   out_4694345153022137407[8] = 0;
   out_4694345153022137407[9] = 0;
   out_4694345153022137407[10] = 0;
   out_4694345153022137407[11] = 0;
   out_4694345153022137407[12] = 1.0;
   out_4694345153022137407[13] = 0;
   out_4694345153022137407[14] = 0;
   out_4694345153022137407[15] = 0;
   out_4694345153022137407[16] = 0;
   out_4694345153022137407[17] = 0;
   out_4694345153022137407[18] = 0;
   out_4694345153022137407[19] = 0;
   out_4694345153022137407[20] = 0;
   out_4694345153022137407[21] = 0;
   out_4694345153022137407[22] = 0;
   out_4694345153022137407[23] = 0;
   out_4694345153022137407[24] = 1.0;
   out_4694345153022137407[25] = 0;
   out_4694345153022137407[26] = 0;
   out_4694345153022137407[27] = 0;
   out_4694345153022137407[28] = 0;
   out_4694345153022137407[29] = 0;
   out_4694345153022137407[30] = 0;
   out_4694345153022137407[31] = 0;
   out_4694345153022137407[32] = 0;
   out_4694345153022137407[33] = 0;
   out_4694345153022137407[34] = 0;
   out_4694345153022137407[35] = 0;
   out_4694345153022137407[36] = 1.0;
   out_4694345153022137407[37] = 0;
   out_4694345153022137407[38] = 0;
   out_4694345153022137407[39] = 0;
   out_4694345153022137407[40] = 0;
   out_4694345153022137407[41] = 0;
   out_4694345153022137407[42] = 0;
   out_4694345153022137407[43] = 0;
   out_4694345153022137407[44] = 0;
   out_4694345153022137407[45] = 0;
   out_4694345153022137407[46] = 0;
   out_4694345153022137407[47] = 0;
   out_4694345153022137407[48] = 1.0;
   out_4694345153022137407[49] = 0;
   out_4694345153022137407[50] = 0;
   out_4694345153022137407[51] = 0;
   out_4694345153022137407[52] = 0;
   out_4694345153022137407[53] = 0;
   out_4694345153022137407[54] = 0;
   out_4694345153022137407[55] = 0;
   out_4694345153022137407[56] = 0;
   out_4694345153022137407[57] = 0;
   out_4694345153022137407[58] = 0;
   out_4694345153022137407[59] = 0;
   out_4694345153022137407[60] = 1.0;
   out_4694345153022137407[61] = 0;
   out_4694345153022137407[62] = 0;
   out_4694345153022137407[63] = 0;
   out_4694345153022137407[64] = 0;
   out_4694345153022137407[65] = 0;
   out_4694345153022137407[66] = 0;
   out_4694345153022137407[67] = 0;
   out_4694345153022137407[68] = 0;
   out_4694345153022137407[69] = 0;
   out_4694345153022137407[70] = 0;
   out_4694345153022137407[71] = 0;
   out_4694345153022137407[72] = 1.0;
   out_4694345153022137407[73] = 0;
   out_4694345153022137407[74] = 0;
   out_4694345153022137407[75] = 0;
   out_4694345153022137407[76] = 0;
   out_4694345153022137407[77] = 0;
   out_4694345153022137407[78] = 0;
   out_4694345153022137407[79] = 0;
   out_4694345153022137407[80] = 0;
   out_4694345153022137407[81] = 0;
   out_4694345153022137407[82] = 0;
   out_4694345153022137407[83] = 0;
   out_4694345153022137407[84] = 1.0;
   out_4694345153022137407[85] = 0;
   out_4694345153022137407[86] = 0;
   out_4694345153022137407[87] = 0;
   out_4694345153022137407[88] = 0;
   out_4694345153022137407[89] = 0;
   out_4694345153022137407[90] = 0;
   out_4694345153022137407[91] = 0;
   out_4694345153022137407[92] = 0;
   out_4694345153022137407[93] = 0;
   out_4694345153022137407[94] = 0;
   out_4694345153022137407[95] = 0;
   out_4694345153022137407[96] = 1.0;
   out_4694345153022137407[97] = 0;
   out_4694345153022137407[98] = 0;
   out_4694345153022137407[99] = 0;
   out_4694345153022137407[100] = 0;
   out_4694345153022137407[101] = 0;
   out_4694345153022137407[102] = 0;
   out_4694345153022137407[103] = 0;
   out_4694345153022137407[104] = 0;
   out_4694345153022137407[105] = 0;
   out_4694345153022137407[106] = 0;
   out_4694345153022137407[107] = 0;
   out_4694345153022137407[108] = 1.0;
   out_4694345153022137407[109] = 0;
   out_4694345153022137407[110] = 0;
   out_4694345153022137407[111] = 0;
   out_4694345153022137407[112] = 0;
   out_4694345153022137407[113] = 0;
   out_4694345153022137407[114] = 0;
   out_4694345153022137407[115] = 0;
   out_4694345153022137407[116] = 0;
   out_4694345153022137407[117] = 0;
   out_4694345153022137407[118] = 0;
   out_4694345153022137407[119] = 0;
   out_4694345153022137407[120] = 1.0;
}
void f_fun(double *state, double dt, double *out_3653497788380929555) {
   out_3653497788380929555[0] = dt*state[3] + state[0];
   out_3653497788380929555[1] = dt*state[4] + state[1];
   out_3653497788380929555[2] = dt*state[5] + state[2];
   out_3653497788380929555[3] = state[3];
   out_3653497788380929555[4] = state[4];
   out_3653497788380929555[5] = state[5];
   out_3653497788380929555[6] = dt*state[7] + state[6];
   out_3653497788380929555[7] = dt*state[8] + state[7];
   out_3653497788380929555[8] = state[8];
   out_3653497788380929555[9] = state[9];
   out_3653497788380929555[10] = state[10];
}
void F_fun(double *state, double dt, double *out_2199281361334248195) {
   out_2199281361334248195[0] = 1;
   out_2199281361334248195[1] = 0;
   out_2199281361334248195[2] = 0;
   out_2199281361334248195[3] = dt;
   out_2199281361334248195[4] = 0;
   out_2199281361334248195[5] = 0;
   out_2199281361334248195[6] = 0;
   out_2199281361334248195[7] = 0;
   out_2199281361334248195[8] = 0;
   out_2199281361334248195[9] = 0;
   out_2199281361334248195[10] = 0;
   out_2199281361334248195[11] = 0;
   out_2199281361334248195[12] = 1;
   out_2199281361334248195[13] = 0;
   out_2199281361334248195[14] = 0;
   out_2199281361334248195[15] = dt;
   out_2199281361334248195[16] = 0;
   out_2199281361334248195[17] = 0;
   out_2199281361334248195[18] = 0;
   out_2199281361334248195[19] = 0;
   out_2199281361334248195[20] = 0;
   out_2199281361334248195[21] = 0;
   out_2199281361334248195[22] = 0;
   out_2199281361334248195[23] = 0;
   out_2199281361334248195[24] = 1;
   out_2199281361334248195[25] = 0;
   out_2199281361334248195[26] = 0;
   out_2199281361334248195[27] = dt;
   out_2199281361334248195[28] = 0;
   out_2199281361334248195[29] = 0;
   out_2199281361334248195[30] = 0;
   out_2199281361334248195[31] = 0;
   out_2199281361334248195[32] = 0;
   out_2199281361334248195[33] = 0;
   out_2199281361334248195[34] = 0;
   out_2199281361334248195[35] = 0;
   out_2199281361334248195[36] = 1;
   out_2199281361334248195[37] = 0;
   out_2199281361334248195[38] = 0;
   out_2199281361334248195[39] = 0;
   out_2199281361334248195[40] = 0;
   out_2199281361334248195[41] = 0;
   out_2199281361334248195[42] = 0;
   out_2199281361334248195[43] = 0;
   out_2199281361334248195[44] = 0;
   out_2199281361334248195[45] = 0;
   out_2199281361334248195[46] = 0;
   out_2199281361334248195[47] = 0;
   out_2199281361334248195[48] = 1;
   out_2199281361334248195[49] = 0;
   out_2199281361334248195[50] = 0;
   out_2199281361334248195[51] = 0;
   out_2199281361334248195[52] = 0;
   out_2199281361334248195[53] = 0;
   out_2199281361334248195[54] = 0;
   out_2199281361334248195[55] = 0;
   out_2199281361334248195[56] = 0;
   out_2199281361334248195[57] = 0;
   out_2199281361334248195[58] = 0;
   out_2199281361334248195[59] = 0;
   out_2199281361334248195[60] = 1;
   out_2199281361334248195[61] = 0;
   out_2199281361334248195[62] = 0;
   out_2199281361334248195[63] = 0;
   out_2199281361334248195[64] = 0;
   out_2199281361334248195[65] = 0;
   out_2199281361334248195[66] = 0;
   out_2199281361334248195[67] = 0;
   out_2199281361334248195[68] = 0;
   out_2199281361334248195[69] = 0;
   out_2199281361334248195[70] = 0;
   out_2199281361334248195[71] = 0;
   out_2199281361334248195[72] = 1;
   out_2199281361334248195[73] = dt;
   out_2199281361334248195[74] = 0;
   out_2199281361334248195[75] = 0;
   out_2199281361334248195[76] = 0;
   out_2199281361334248195[77] = 0;
   out_2199281361334248195[78] = 0;
   out_2199281361334248195[79] = 0;
   out_2199281361334248195[80] = 0;
   out_2199281361334248195[81] = 0;
   out_2199281361334248195[82] = 0;
   out_2199281361334248195[83] = 0;
   out_2199281361334248195[84] = 1;
   out_2199281361334248195[85] = dt;
   out_2199281361334248195[86] = 0;
   out_2199281361334248195[87] = 0;
   out_2199281361334248195[88] = 0;
   out_2199281361334248195[89] = 0;
   out_2199281361334248195[90] = 0;
   out_2199281361334248195[91] = 0;
   out_2199281361334248195[92] = 0;
   out_2199281361334248195[93] = 0;
   out_2199281361334248195[94] = 0;
   out_2199281361334248195[95] = 0;
   out_2199281361334248195[96] = 1;
   out_2199281361334248195[97] = 0;
   out_2199281361334248195[98] = 0;
   out_2199281361334248195[99] = 0;
   out_2199281361334248195[100] = 0;
   out_2199281361334248195[101] = 0;
   out_2199281361334248195[102] = 0;
   out_2199281361334248195[103] = 0;
   out_2199281361334248195[104] = 0;
   out_2199281361334248195[105] = 0;
   out_2199281361334248195[106] = 0;
   out_2199281361334248195[107] = 0;
   out_2199281361334248195[108] = 1;
   out_2199281361334248195[109] = 0;
   out_2199281361334248195[110] = 0;
   out_2199281361334248195[111] = 0;
   out_2199281361334248195[112] = 0;
   out_2199281361334248195[113] = 0;
   out_2199281361334248195[114] = 0;
   out_2199281361334248195[115] = 0;
   out_2199281361334248195[116] = 0;
   out_2199281361334248195[117] = 0;
   out_2199281361334248195[118] = 0;
   out_2199281361334248195[119] = 0;
   out_2199281361334248195[120] = 1;
}
void h_6(double *state, double *sat_pos, double *out_2825146410579927360) {
   out_2825146410579927360[0] = sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2)) + state[6];
}
void H_6(double *state, double *sat_pos, double *out_4850413402897355274) {
   out_4850413402897355274[0] = (-sat_pos[0] + state[0])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_4850413402897355274[1] = (-sat_pos[1] + state[1])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_4850413402897355274[2] = (-sat_pos[2] + state[2])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_4850413402897355274[3] = 0;
   out_4850413402897355274[4] = 0;
   out_4850413402897355274[5] = 0;
   out_4850413402897355274[6] = 1;
   out_4850413402897355274[7] = 0;
   out_4850413402897355274[8] = 0;
   out_4850413402897355274[9] = 0;
   out_4850413402897355274[10] = 0;
}
void h_20(double *state, double *sat_pos, double *out_149741099389073143) {
   out_149741099389073143[0] = sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2)) + sat_pos[3]*state[10] + state[6] + state[9];
}
void H_20(double *state, double *sat_pos, double *out_5139884667526395233) {
   out_5139884667526395233[0] = (-sat_pos[0] + state[0])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_5139884667526395233[1] = (-sat_pos[1] + state[1])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_5139884667526395233[2] = (-sat_pos[2] + state[2])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_5139884667526395233[3] = 0;
   out_5139884667526395233[4] = 0;
   out_5139884667526395233[5] = 0;
   out_5139884667526395233[6] = 1;
   out_5139884667526395233[7] = 0;
   out_5139884667526395233[8] = 0;
   out_5139884667526395233[9] = 1;
   out_5139884667526395233[10] = sat_pos[3];
}
void h_7(double *state, double *sat_pos_vel, double *out_6142067295876116682) {
   out_6142067295876116682[0] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[3] - state[3])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[4] - state[4])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + (sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + state[7];
}
void H_7(double *state, double *sat_pos_vel, double *out_682836583427487555) {
   out_682836583427487555[0] = pow(sat_pos_vel[0] - state[0], 2)*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[0] - state[0])*(sat_pos_vel[1] - state[1])*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[0] - state[0])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[3] - state[3])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_682836583427487555[1] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[1] - state[1])*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + pow(sat_pos_vel[1] - state[1], 2)*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[4] - state[4])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_682836583427487555[2] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + pow(sat_pos_vel[2] - state[2], 2)*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[5] - state[5])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_682836583427487555[3] = -(sat_pos_vel[0] - state[0])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_682836583427487555[4] = -(sat_pos_vel[1] - state[1])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_682836583427487555[5] = -(sat_pos_vel[2] - state[2])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_682836583427487555[6] = 0;
   out_682836583427487555[7] = 1;
   out_682836583427487555[8] = 0;
   out_682836583427487555[9] = 0;
   out_682836583427487555[10] = 0;
}
void h_21(double *state, double *sat_pos_vel, double *out_6142067295876116682) {
   out_6142067295876116682[0] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[3] - state[3])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[4] - state[4])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + (sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + state[7];
}
void H_21(double *state, double *sat_pos_vel, double *out_682836583427487555) {
   out_682836583427487555[0] = pow(sat_pos_vel[0] - state[0], 2)*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[0] - state[0])*(sat_pos_vel[1] - state[1])*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[0] - state[0])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[3] - state[3])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_682836583427487555[1] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[1] - state[1])*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + pow(sat_pos_vel[1] - state[1], 2)*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[4] - state[4])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_682836583427487555[2] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + pow(sat_pos_vel[2] - state[2], 2)*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[5] - state[5])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_682836583427487555[3] = -(sat_pos_vel[0] - state[0])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_682836583427487555[4] = -(sat_pos_vel[1] - state[1])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_682836583427487555[5] = -(sat_pos_vel[2] - state[2])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_682836583427487555[6] = 0;
   out_682836583427487555[7] = 1;
   out_682836583427487555[8] = 0;
   out_682836583427487555[9] = 0;
   out_682836583427487555[10] = 0;
}
#include <eigen3/Eigen/Dense>
#include <iostream>

typedef Eigen::Matrix<double, DIM, DIM, Eigen::RowMajor> DDM;
typedef Eigen::Matrix<double, EDIM, EDIM, Eigen::RowMajor> EEM;
typedef Eigen::Matrix<double, DIM, EDIM, Eigen::RowMajor> DEM;

void predict(double *in_x, double *in_P, double *in_Q, double dt) {
  typedef Eigen::Matrix<double, MEDIM, MEDIM, Eigen::RowMajor> RRM;

  double nx[DIM] = {0};
  double in_F[EDIM*EDIM] = {0};

  // functions from sympy
  f_fun(in_x, dt, nx);
  F_fun(in_x, dt, in_F);


  EEM F(in_F);
  EEM P(in_P);
  EEM Q(in_Q);

  RRM F_main = F.topLeftCorner(MEDIM, MEDIM);
  P.topLeftCorner(MEDIM, MEDIM) = (F_main * P.topLeftCorner(MEDIM, MEDIM)) * F_main.transpose();
  P.topRightCorner(MEDIM, EDIM - MEDIM) = F_main * P.topRightCorner(MEDIM, EDIM - MEDIM);
  P.bottomLeftCorner(EDIM - MEDIM, MEDIM) = P.bottomLeftCorner(EDIM - MEDIM, MEDIM) * F_main.transpose();

  P = P + dt*Q;

  // copy out state
  memcpy(in_x, nx, DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
}

// note: extra_args dim only correct when null space projecting
// otherwise 1
template <int ZDIM, int EADIM, bool MAHA_TEST>
void update(double *in_x, double *in_P, Hfun h_fun, Hfun H_fun, Hfun Hea_fun, double *in_z, double *in_R, double *in_ea, double MAHA_THRESHOLD) {
  typedef Eigen::Matrix<double, ZDIM, ZDIM, Eigen::RowMajor> ZZM;
  typedef Eigen::Matrix<double, ZDIM, DIM, Eigen::RowMajor> ZDM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, EDIM, Eigen::RowMajor> XEM;
  //typedef Eigen::Matrix<double, EDIM, ZDIM, Eigen::RowMajor> EZM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, 1> X1M;
  typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> XXM;

  double in_hx[ZDIM] = {0};
  double in_H[ZDIM * DIM] = {0};
  double in_H_mod[EDIM * DIM] = {0};
  double delta_x[EDIM] = {0};
  double x_new[DIM] = {0};


  // state x, P
  Eigen::Matrix<double, ZDIM, 1> z(in_z);
  EEM P(in_P);
  ZZM pre_R(in_R);

  // functions from sympy
  h_fun(in_x, in_ea, in_hx);
  H_fun(in_x, in_ea, in_H);
  ZDM pre_H(in_H);

  // get y (y = z - hx)
  Eigen::Matrix<double, ZDIM, 1> pre_y(in_hx); pre_y = z - pre_y;
  X1M y; XXM H; XXM R;
  if (Hea_fun){
    typedef Eigen::Matrix<double, ZDIM, EADIM, Eigen::RowMajor> ZAM;
    double in_Hea[ZDIM * EADIM] = {0};
    Hea_fun(in_x, in_ea, in_Hea);
    ZAM Hea(in_Hea);
    XXM A = Hea.transpose().fullPivLu().kernel();


    y = A.transpose() * pre_y;
    H = A.transpose() * pre_H;
    R = A.transpose() * pre_R * A;
  } else {
    y = pre_y;
    H = pre_H;
    R = pre_R;
  }
  // get modified H
  H_mod_fun(in_x, in_H_mod);
  DEM H_mod(in_H_mod);
  XEM H_err = H * H_mod;

  // Do mahalobis distance test
  if (MAHA_TEST){
    XXM a = (H_err * P * H_err.transpose() + R).inverse();
    double maha_dist = y.transpose() * a * y;
    if (maha_dist > MAHA_THRESHOLD){
      R = 1.0e16 * R;
    }
  }

  // Outlier resilient weighting
  double weight = 1;//(1.5)/(1 + y.squaredNorm()/R.sum());

  // kalman gains and I_KH
  XXM S = ((H_err * P) * H_err.transpose()) + R/weight;
  XEM KT = S.fullPivLu().solve(H_err * P.transpose());
  //EZM K = KT.transpose(); TODO: WHY DOES THIS NOT COMPILE?
  //EZM K = S.fullPivLu().solve(H_err * P.transpose()).transpose();
  //std::cout << "Here is the matrix rot:\n" << K << std::endl;
  EEM I_KH = Eigen::Matrix<double, EDIM, EDIM>::Identity() - (KT.transpose() * H_err);

  // update state by injecting dx
  Eigen::Matrix<double, EDIM, 1> dx(delta_x);
  dx  = (KT.transpose() * y);
  memcpy(delta_x, dx.data(), EDIM * sizeof(double));
  err_fun(in_x, delta_x, x_new);
  Eigen::Matrix<double, DIM, 1> x(x_new);

  // update cov
  P = ((I_KH * P) * I_KH.transpose()) + ((KT.transpose() * R) * KT);

  // copy out state
  memcpy(in_x, x.data(), DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
  memcpy(in_z, y.data(), y.rows() * sizeof(double));
}




}
extern "C" {

void gnss_update_6(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_6, H_6, NULL, in_z, in_R, in_ea, MAHA_THRESH_6);
}
void gnss_update_20(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_20, H_20, NULL, in_z, in_R, in_ea, MAHA_THRESH_20);
}
void gnss_update_7(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_7, H_7, NULL, in_z, in_R, in_ea, MAHA_THRESH_7);
}
void gnss_update_21(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_21, H_21, NULL, in_z, in_R, in_ea, MAHA_THRESH_21);
}
void gnss_err_fun(double *nom_x, double *delta_x, double *out_8031618320293225418) {
  err_fun(nom_x, delta_x, out_8031618320293225418);
}
void gnss_inv_err_fun(double *nom_x, double *true_x, double *out_338273384091461970) {
  inv_err_fun(nom_x, true_x, out_338273384091461970);
}
void gnss_H_mod_fun(double *state, double *out_4694345153022137407) {
  H_mod_fun(state, out_4694345153022137407);
}
void gnss_f_fun(double *state, double dt, double *out_3653497788380929555) {
  f_fun(state,  dt, out_3653497788380929555);
}
void gnss_F_fun(double *state, double dt, double *out_2199281361334248195) {
  F_fun(state,  dt, out_2199281361334248195);
}
void gnss_h_6(double *state, double *sat_pos, double *out_2825146410579927360) {
  h_6(state, sat_pos, out_2825146410579927360);
}
void gnss_H_6(double *state, double *sat_pos, double *out_4850413402897355274) {
  H_6(state, sat_pos, out_4850413402897355274);
}
void gnss_h_20(double *state, double *sat_pos, double *out_149741099389073143) {
  h_20(state, sat_pos, out_149741099389073143);
}
void gnss_H_20(double *state, double *sat_pos, double *out_5139884667526395233) {
  H_20(state, sat_pos, out_5139884667526395233);
}
void gnss_h_7(double *state, double *sat_pos_vel, double *out_6142067295876116682) {
  h_7(state, sat_pos_vel, out_6142067295876116682);
}
void gnss_H_7(double *state, double *sat_pos_vel, double *out_682836583427487555) {
  H_7(state, sat_pos_vel, out_682836583427487555);
}
void gnss_h_21(double *state, double *sat_pos_vel, double *out_6142067295876116682) {
  h_21(state, sat_pos_vel, out_6142067295876116682);
}
void gnss_H_21(double *state, double *sat_pos_vel, double *out_682836583427487555) {
  H_21(state, sat_pos_vel, out_682836583427487555);
}
void gnss_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
}

const EKF gnss = {
  .name = "gnss",
  .kinds = { 6, 20, 7, 21 },
  .feature_kinds = {  },
  .f_fun = gnss_f_fun,
  .F_fun = gnss_F_fun,
  .err_fun = gnss_err_fun,
  .inv_err_fun = gnss_inv_err_fun,
  .H_mod_fun = gnss_H_mod_fun,
  .predict = gnss_predict,
  .hs = {
    { 6, gnss_h_6 },
    { 20, gnss_h_20 },
    { 7, gnss_h_7 },
    { 21, gnss_h_21 },
  },
  .Hs = {
    { 6, gnss_H_6 },
    { 20, gnss_H_20 },
    { 7, gnss_H_7 },
    { 21, gnss_H_21 },
  },
  .updates = {
    { 6, gnss_update_6 },
    { 20, gnss_update_20 },
    { 7, gnss_update_7 },
    { 21, gnss_update_21 },
  },
  .Hes = {
  },
  .sets = {
  },
  .extra_routines = {
  },
};

ekf_init(gnss);
