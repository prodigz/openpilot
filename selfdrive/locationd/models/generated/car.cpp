#include "car.h"

namespace {
#define DIM 9
#define EDIM 9
#define MEDIM 9
typedef void (*Hfun)(double *, double *, double *);

double mass;

void set_mass(double x){ mass = x;}

double rotational_inertia;

void set_rotational_inertia(double x){ rotational_inertia = x;}

double center_to_front;

void set_center_to_front(double x){ center_to_front = x;}

double center_to_rear;

void set_center_to_rear(double x){ center_to_rear = x;}

double stiffness_front;

void set_stiffness_front(double x){ stiffness_front = x;}

double stiffness_rear;

void set_stiffness_rear(double x){ stiffness_rear = x;}
const static double MAHA_THRESH_25 = 3.8414588206941227;
const static double MAHA_THRESH_24 = 5.991464547107981;
const static double MAHA_THRESH_30 = 3.8414588206941227;
const static double MAHA_THRESH_26 = 3.8414588206941227;
const static double MAHA_THRESH_27 = 3.8414588206941227;
const static double MAHA_THRESH_29 = 3.8414588206941227;
const static double MAHA_THRESH_28 = 3.8414588206941227;
const static double MAHA_THRESH_31 = 3.8414588206941227;

/******************************************************************************
 *                      Code generated with SymPy 1.11.1                      *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_7806729380221151220) {
   out_7806729380221151220[0] = delta_x[0] + nom_x[0];
   out_7806729380221151220[1] = delta_x[1] + nom_x[1];
   out_7806729380221151220[2] = delta_x[2] + nom_x[2];
   out_7806729380221151220[3] = delta_x[3] + nom_x[3];
   out_7806729380221151220[4] = delta_x[4] + nom_x[4];
   out_7806729380221151220[5] = delta_x[5] + nom_x[5];
   out_7806729380221151220[6] = delta_x[6] + nom_x[6];
   out_7806729380221151220[7] = delta_x[7] + nom_x[7];
   out_7806729380221151220[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_5704254474892688384) {
   out_5704254474892688384[0] = -nom_x[0] + true_x[0];
   out_5704254474892688384[1] = -nom_x[1] + true_x[1];
   out_5704254474892688384[2] = -nom_x[2] + true_x[2];
   out_5704254474892688384[3] = -nom_x[3] + true_x[3];
   out_5704254474892688384[4] = -nom_x[4] + true_x[4];
   out_5704254474892688384[5] = -nom_x[5] + true_x[5];
   out_5704254474892688384[6] = -nom_x[6] + true_x[6];
   out_5704254474892688384[7] = -nom_x[7] + true_x[7];
   out_5704254474892688384[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_4208275903993616188) {
   out_4208275903993616188[0] = 1.0;
   out_4208275903993616188[1] = 0;
   out_4208275903993616188[2] = 0;
   out_4208275903993616188[3] = 0;
   out_4208275903993616188[4] = 0;
   out_4208275903993616188[5] = 0;
   out_4208275903993616188[6] = 0;
   out_4208275903993616188[7] = 0;
   out_4208275903993616188[8] = 0;
   out_4208275903993616188[9] = 0;
   out_4208275903993616188[10] = 1.0;
   out_4208275903993616188[11] = 0;
   out_4208275903993616188[12] = 0;
   out_4208275903993616188[13] = 0;
   out_4208275903993616188[14] = 0;
   out_4208275903993616188[15] = 0;
   out_4208275903993616188[16] = 0;
   out_4208275903993616188[17] = 0;
   out_4208275903993616188[18] = 0;
   out_4208275903993616188[19] = 0;
   out_4208275903993616188[20] = 1.0;
   out_4208275903993616188[21] = 0;
   out_4208275903993616188[22] = 0;
   out_4208275903993616188[23] = 0;
   out_4208275903993616188[24] = 0;
   out_4208275903993616188[25] = 0;
   out_4208275903993616188[26] = 0;
   out_4208275903993616188[27] = 0;
   out_4208275903993616188[28] = 0;
   out_4208275903993616188[29] = 0;
   out_4208275903993616188[30] = 1.0;
   out_4208275903993616188[31] = 0;
   out_4208275903993616188[32] = 0;
   out_4208275903993616188[33] = 0;
   out_4208275903993616188[34] = 0;
   out_4208275903993616188[35] = 0;
   out_4208275903993616188[36] = 0;
   out_4208275903993616188[37] = 0;
   out_4208275903993616188[38] = 0;
   out_4208275903993616188[39] = 0;
   out_4208275903993616188[40] = 1.0;
   out_4208275903993616188[41] = 0;
   out_4208275903993616188[42] = 0;
   out_4208275903993616188[43] = 0;
   out_4208275903993616188[44] = 0;
   out_4208275903993616188[45] = 0;
   out_4208275903993616188[46] = 0;
   out_4208275903993616188[47] = 0;
   out_4208275903993616188[48] = 0;
   out_4208275903993616188[49] = 0;
   out_4208275903993616188[50] = 1.0;
   out_4208275903993616188[51] = 0;
   out_4208275903993616188[52] = 0;
   out_4208275903993616188[53] = 0;
   out_4208275903993616188[54] = 0;
   out_4208275903993616188[55] = 0;
   out_4208275903993616188[56] = 0;
   out_4208275903993616188[57] = 0;
   out_4208275903993616188[58] = 0;
   out_4208275903993616188[59] = 0;
   out_4208275903993616188[60] = 1.0;
   out_4208275903993616188[61] = 0;
   out_4208275903993616188[62] = 0;
   out_4208275903993616188[63] = 0;
   out_4208275903993616188[64] = 0;
   out_4208275903993616188[65] = 0;
   out_4208275903993616188[66] = 0;
   out_4208275903993616188[67] = 0;
   out_4208275903993616188[68] = 0;
   out_4208275903993616188[69] = 0;
   out_4208275903993616188[70] = 1.0;
   out_4208275903993616188[71] = 0;
   out_4208275903993616188[72] = 0;
   out_4208275903993616188[73] = 0;
   out_4208275903993616188[74] = 0;
   out_4208275903993616188[75] = 0;
   out_4208275903993616188[76] = 0;
   out_4208275903993616188[77] = 0;
   out_4208275903993616188[78] = 0;
   out_4208275903993616188[79] = 0;
   out_4208275903993616188[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_434195176901812415) {
   out_434195176901812415[0] = state[0];
   out_434195176901812415[1] = state[1];
   out_434195176901812415[2] = state[2];
   out_434195176901812415[3] = state[3];
   out_434195176901812415[4] = state[4];
   out_434195176901812415[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8000000000000007*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_434195176901812415[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_434195176901812415[7] = state[7];
   out_434195176901812415[8] = state[8];
}
void F_fun(double *state, double dt, double *out_4166634264733628142) {
   out_4166634264733628142[0] = 1;
   out_4166634264733628142[1] = 0;
   out_4166634264733628142[2] = 0;
   out_4166634264733628142[3] = 0;
   out_4166634264733628142[4] = 0;
   out_4166634264733628142[5] = 0;
   out_4166634264733628142[6] = 0;
   out_4166634264733628142[7] = 0;
   out_4166634264733628142[8] = 0;
   out_4166634264733628142[9] = 0;
   out_4166634264733628142[10] = 1;
   out_4166634264733628142[11] = 0;
   out_4166634264733628142[12] = 0;
   out_4166634264733628142[13] = 0;
   out_4166634264733628142[14] = 0;
   out_4166634264733628142[15] = 0;
   out_4166634264733628142[16] = 0;
   out_4166634264733628142[17] = 0;
   out_4166634264733628142[18] = 0;
   out_4166634264733628142[19] = 0;
   out_4166634264733628142[20] = 1;
   out_4166634264733628142[21] = 0;
   out_4166634264733628142[22] = 0;
   out_4166634264733628142[23] = 0;
   out_4166634264733628142[24] = 0;
   out_4166634264733628142[25] = 0;
   out_4166634264733628142[26] = 0;
   out_4166634264733628142[27] = 0;
   out_4166634264733628142[28] = 0;
   out_4166634264733628142[29] = 0;
   out_4166634264733628142[30] = 1;
   out_4166634264733628142[31] = 0;
   out_4166634264733628142[32] = 0;
   out_4166634264733628142[33] = 0;
   out_4166634264733628142[34] = 0;
   out_4166634264733628142[35] = 0;
   out_4166634264733628142[36] = 0;
   out_4166634264733628142[37] = 0;
   out_4166634264733628142[38] = 0;
   out_4166634264733628142[39] = 0;
   out_4166634264733628142[40] = 1;
   out_4166634264733628142[41] = 0;
   out_4166634264733628142[42] = 0;
   out_4166634264733628142[43] = 0;
   out_4166634264733628142[44] = 0;
   out_4166634264733628142[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_4166634264733628142[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_4166634264733628142[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_4166634264733628142[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_4166634264733628142[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_4166634264733628142[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_4166634264733628142[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_4166634264733628142[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_4166634264733628142[53] = -9.8000000000000007*dt;
   out_4166634264733628142[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_4166634264733628142[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_4166634264733628142[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_4166634264733628142[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_4166634264733628142[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_4166634264733628142[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_4166634264733628142[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_4166634264733628142[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_4166634264733628142[62] = 0;
   out_4166634264733628142[63] = 0;
   out_4166634264733628142[64] = 0;
   out_4166634264733628142[65] = 0;
   out_4166634264733628142[66] = 0;
   out_4166634264733628142[67] = 0;
   out_4166634264733628142[68] = 0;
   out_4166634264733628142[69] = 0;
   out_4166634264733628142[70] = 1;
   out_4166634264733628142[71] = 0;
   out_4166634264733628142[72] = 0;
   out_4166634264733628142[73] = 0;
   out_4166634264733628142[74] = 0;
   out_4166634264733628142[75] = 0;
   out_4166634264733628142[76] = 0;
   out_4166634264733628142[77] = 0;
   out_4166634264733628142[78] = 0;
   out_4166634264733628142[79] = 0;
   out_4166634264733628142[80] = 1;
}
void h_25(double *state, double *unused, double *out_5910888359297314153) {
   out_5910888359297314153[0] = state[6];
}
void H_25(double *state, double *unused, double *out_6947792830194027240) {
   out_6947792830194027240[0] = 0;
   out_6947792830194027240[1] = 0;
   out_6947792830194027240[2] = 0;
   out_6947792830194027240[3] = 0;
   out_6947792830194027240[4] = 0;
   out_6947792830194027240[5] = 0;
   out_6947792830194027240[6] = 1;
   out_6947792830194027240[7] = 0;
   out_6947792830194027240[8] = 0;
}
void h_24(double *state, double *unused, double *out_2008521997787469843) {
   out_2008521997787469843[0] = state[4];
   out_2008521997787469843[1] = state[5];
}
void H_24(double *state, double *unused, double *out_9120442429199526806) {
   out_9120442429199526806[0] = 0;
   out_9120442429199526806[1] = 0;
   out_9120442429199526806[2] = 0;
   out_9120442429199526806[3] = 0;
   out_9120442429199526806[4] = 1;
   out_9120442429199526806[5] = 0;
   out_9120442429199526806[6] = 0;
   out_9120442429199526806[7] = 0;
   out_9120442429199526806[8] = 0;
   out_9120442429199526806[9] = 0;
   out_9120442429199526806[10] = 0;
   out_9120442429199526806[11] = 0;
   out_9120442429199526806[12] = 0;
   out_9120442429199526806[13] = 0;
   out_9120442429199526806[14] = 1;
   out_9120442429199526806[15] = 0;
   out_9120442429199526806[16] = 0;
   out_9120442429199526806[17] = 0;
}
void h_30(double *state, double *unused, double *out_5753701690946185008) {
   out_5753701690946185008[0] = state[4];
}
void H_30(double *state, double *unused, double *out_4429459871686778613) {
   out_4429459871686778613[0] = 0;
   out_4429459871686778613[1] = 0;
   out_4429459871686778613[2] = 0;
   out_4429459871686778613[3] = 0;
   out_4429459871686778613[4] = 1;
   out_4429459871686778613[5] = 0;
   out_4429459871686778613[6] = 0;
   out_4429459871686778613[7] = 0;
   out_4429459871686778613[8] = 0;
}
void h_26(double *state, double *unused, double *out_3711073210756525843) {
   out_3711073210756525843[0] = state[7];
}
void H_26(double *state, double *unused, double *out_7757447924641468152) {
   out_7757447924641468152[0] = 0;
   out_7757447924641468152[1] = 0;
   out_7757447924641468152[2] = 0;
   out_7757447924641468152[3] = 0;
   out_7757447924641468152[4] = 0;
   out_7757447924641468152[5] = 0;
   out_7757447924641468152[6] = 0;
   out_7757447924641468152[7] = 1;
   out_7757447924641468152[8] = 0;
}
void h_27(double *state, double *unused, double *out_6514204243973791670) {
   out_6514204243973791670[0] = state[3];
}
void H_27(double *state, double *unused, double *out_6604223183487203524) {
   out_6604223183487203524[0] = 0;
   out_6604223183487203524[1] = 0;
   out_6604223183487203524[2] = 0;
   out_6604223183487203524[3] = 1;
   out_6604223183487203524[4] = 0;
   out_6604223183487203524[5] = 0;
   out_6604223183487203524[6] = 0;
   out_6604223183487203524[7] = 0;
   out_6604223183487203524[8] = 0;
}
void h_29(double *state, double *unused, double *out_8295090301481737596) {
   out_8295090301481737596[0] = state[1];
}
void H_29(double *state, double *unused, double *out_3919228527372386429) {
   out_3919228527372386429[0] = 0;
   out_3919228527372386429[1] = 1;
   out_3919228527372386429[2] = 0;
   out_3919228527372386429[3] = 0;
   out_3919228527372386429[4] = 0;
   out_3919228527372386429[5] = 0;
   out_3919228527372386429[6] = 0;
   out_3919228527372386429[7] = 0;
   out_3919228527372386429[8] = 0;
}
void h_28(double *state, double *unused, double *out_8789733061586843804) {
   out_8789733061586843804[0] = state[0];
}
void H_28(double *state, double *unused, double *out_9001627544441917003) {
   out_9001627544441917003[0] = 1;
   out_9001627544441917003[1] = 0;
   out_9001627544441917003[2] = 0;
   out_9001627544441917003[3] = 0;
   out_9001627544441917003[4] = 0;
   out_9001627544441917003[5] = 0;
   out_9001627544441917003[6] = 0;
   out_9001627544441917003[7] = 0;
   out_9001627544441917003[8] = 0;
}
void h_31(double *state, double *unused, double *out_2963162368941829192) {
   out_2963162368941829192[0] = state[8];
}
void H_31(double *state, double *unused, double *out_7131239822408116676) {
   out_7131239822408116676[0] = 0;
   out_7131239822408116676[1] = 0;
   out_7131239822408116676[2] = 0;
   out_7131239822408116676[3] = 0;
   out_7131239822408116676[4] = 0;
   out_7131239822408116676[5] = 0;
   out_7131239822408116676[6] = 0;
   out_7131239822408116676[7] = 0;
   out_7131239822408116676[8] = 1;
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

void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_25, H_25, NULL, in_z, in_R, in_ea, MAHA_THRESH_25);
}
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<2, 3, 0>(in_x, in_P, h_24, H_24, NULL, in_z, in_R, in_ea, MAHA_THRESH_24);
}
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_30, H_30, NULL, in_z, in_R, in_ea, MAHA_THRESH_30);
}
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_26, H_26, NULL, in_z, in_R, in_ea, MAHA_THRESH_26);
}
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_27, H_27, NULL, in_z, in_R, in_ea, MAHA_THRESH_27);
}
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_29, H_29, NULL, in_z, in_R, in_ea, MAHA_THRESH_29);
}
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_28, H_28, NULL, in_z, in_R, in_ea, MAHA_THRESH_28);
}
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_31, H_31, NULL, in_z, in_R, in_ea, MAHA_THRESH_31);
}
void car_err_fun(double *nom_x, double *delta_x, double *out_7806729380221151220) {
  err_fun(nom_x, delta_x, out_7806729380221151220);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_5704254474892688384) {
  inv_err_fun(nom_x, true_x, out_5704254474892688384);
}
void car_H_mod_fun(double *state, double *out_4208275903993616188) {
  H_mod_fun(state, out_4208275903993616188);
}
void car_f_fun(double *state, double dt, double *out_434195176901812415) {
  f_fun(state,  dt, out_434195176901812415);
}
void car_F_fun(double *state, double dt, double *out_4166634264733628142) {
  F_fun(state,  dt, out_4166634264733628142);
}
void car_h_25(double *state, double *unused, double *out_5910888359297314153) {
  h_25(state, unused, out_5910888359297314153);
}
void car_H_25(double *state, double *unused, double *out_6947792830194027240) {
  H_25(state, unused, out_6947792830194027240);
}
void car_h_24(double *state, double *unused, double *out_2008521997787469843) {
  h_24(state, unused, out_2008521997787469843);
}
void car_H_24(double *state, double *unused, double *out_9120442429199526806) {
  H_24(state, unused, out_9120442429199526806);
}
void car_h_30(double *state, double *unused, double *out_5753701690946185008) {
  h_30(state, unused, out_5753701690946185008);
}
void car_H_30(double *state, double *unused, double *out_4429459871686778613) {
  H_30(state, unused, out_4429459871686778613);
}
void car_h_26(double *state, double *unused, double *out_3711073210756525843) {
  h_26(state, unused, out_3711073210756525843);
}
void car_H_26(double *state, double *unused, double *out_7757447924641468152) {
  H_26(state, unused, out_7757447924641468152);
}
void car_h_27(double *state, double *unused, double *out_6514204243973791670) {
  h_27(state, unused, out_6514204243973791670);
}
void car_H_27(double *state, double *unused, double *out_6604223183487203524) {
  H_27(state, unused, out_6604223183487203524);
}
void car_h_29(double *state, double *unused, double *out_8295090301481737596) {
  h_29(state, unused, out_8295090301481737596);
}
void car_H_29(double *state, double *unused, double *out_3919228527372386429) {
  H_29(state, unused, out_3919228527372386429);
}
void car_h_28(double *state, double *unused, double *out_8789733061586843804) {
  h_28(state, unused, out_8789733061586843804);
}
void car_H_28(double *state, double *unused, double *out_9001627544441917003) {
  H_28(state, unused, out_9001627544441917003);
}
void car_h_31(double *state, double *unused, double *out_2963162368941829192) {
  h_31(state, unused, out_2963162368941829192);
}
void car_H_31(double *state, double *unused, double *out_7131239822408116676) {
  H_31(state, unused, out_7131239822408116676);
}
void car_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
void car_set_mass(double x) {
  set_mass(x);
}
void car_set_rotational_inertia(double x) {
  set_rotational_inertia(x);
}
void car_set_center_to_front(double x) {
  set_center_to_front(x);
}
void car_set_center_to_rear(double x) {
  set_center_to_rear(x);
}
void car_set_stiffness_front(double x) {
  set_stiffness_front(x);
}
void car_set_stiffness_rear(double x) {
  set_stiffness_rear(x);
}
}

const EKF car = {
  .name = "car",
  .kinds = { 25, 24, 30, 26, 27, 29, 28, 31 },
  .feature_kinds = {  },
  .f_fun = car_f_fun,
  .F_fun = car_F_fun,
  .err_fun = car_err_fun,
  .inv_err_fun = car_inv_err_fun,
  .H_mod_fun = car_H_mod_fun,
  .predict = car_predict,
  .hs = {
    { 25, car_h_25 },
    { 24, car_h_24 },
    { 30, car_h_30 },
    { 26, car_h_26 },
    { 27, car_h_27 },
    { 29, car_h_29 },
    { 28, car_h_28 },
    { 31, car_h_31 },
  },
  .Hs = {
    { 25, car_H_25 },
    { 24, car_H_24 },
    { 30, car_H_30 },
    { 26, car_H_26 },
    { 27, car_H_27 },
    { 29, car_H_29 },
    { 28, car_H_28 },
    { 31, car_H_31 },
  },
  .updates = {
    { 25, car_update_25 },
    { 24, car_update_24 },
    { 30, car_update_30 },
    { 26, car_update_26 },
    { 27, car_update_27 },
    { 29, car_update_29 },
    { 28, car_update_28 },
    { 31, car_update_31 },
  },
  .Hes = {
  },
  .sets = {
    { "mass", car_set_mass },
    { "rotational_inertia", car_set_rotational_inertia },
    { "center_to_front", car_set_center_to_front },
    { "center_to_rear", car_set_center_to_rear },
    { "stiffness_front", car_set_stiffness_front },
    { "stiffness_rear", car_set_stiffness_rear },
  },
  .extra_routines = {
  },
};

ekf_init(car);
