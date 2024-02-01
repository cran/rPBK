// Generated by rstantools.  Do not edit by hand.

/*
    rPBK is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    rPBK is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with rPBK.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef MODELS_HPP
#define MODELS_HPP
#define STAN__SERVICES__COMMAND_HPP
#ifndef USE_STANC3
#define USE_STANC3
#endif
#include <rstan/rstaninc.hpp>
// Code generated by stanc v2.32.2
#include <stan/model/model_header.hpp>
namespace model_export_interpolate_namespace {
using stan::model::model_base_crtp;
using namespace stan::math;
stan::math::profile_map profiles__;
static constexpr std::array<const char*, 60> locations_array__ =
  {" (found before start of program)",
  " (in 'export_interpolate', line 65, column 2 to column 9)",
  " (in 'export_interpolate', line 66, column 2 to column 31)",
  " (in 'export_interpolate', line 55, column 2 to column 9)",
  " (in 'export_interpolate', line 56, column 2 to column 8)",
  " (in 'export_interpolate', line 57, column 9 to column 10)",
  " (in 'export_interpolate', line 57, column 2 to column 16)",
  " (in 'export_interpolate', line 58, column 9 to column 10)",
  " (in 'export_interpolate', line 58, column 2 to column 16)",
  " (in 'export_interpolate', line 4, column 2 to column 13)",
  " (in 'export_interpolate', line 12, column 6 to column 15)",
  " (in 'export_interpolate', line 11, column 24 to line 13, column 5)",
  " (in 'export_interpolate', line 11, column 4 to line 13, column 5)",
  " (in 'export_interpolate', line 14, column 4 to column 14)",
  " (in 'export_interpolate', line 10, column 9 to line 15, column 3)",
  " (in 'export_interpolate', line 9, column 4 to column 14)",
  " (in 'export_interpolate', line 8, column 39 to line 10, column 3)",
  " (in 'export_interpolate', line 8, column 9 to line 15, column 3)",
  " (in 'export_interpolate', line 6, column 4 to column 30)",
  " (in 'export_interpolate', line 7, column 4 to column 14)",
  " (in 'export_interpolate', line 5, column 18 to line 8, column 3)",
  " (in 'export_interpolate', line 5, column 2 to line 15, column 3)",
  " (in 'export_interpolate', line 3, column 33 to line 16, column 1)",
  " (in 'export_interpolate', line 23, column 4 to column 16)",
  " (in 'export_interpolate', line 22, column 8 to line 24, column 3)",
  " (in 'export_interpolate', line 20, column 4 to column 33)",
  " (in 'export_interpolate', line 21, column 4 to column 90)",
  " (in 'export_interpolate', line 19, column 36 to line 22, column 3)",
  " (in 'export_interpolate', line 19, column 2 to line 24, column 3)",
  " (in 'export_interpolate', line 18, column 48 to line 25, column 1)",
  " (in 'export_interpolate', line 28, column 9 to column 15)",
  " (in 'export_interpolate', line 28, column 16 to column 22)",
  " (in 'export_interpolate', line 28, column 2 to column 44)",
  " (in 'export_interpolate', line 29, column 9 to column 15)",
  " (in 'export_interpolate', line 29, column 16 to column 22)",
  " (in 'export_interpolate', line 29, column 2 to column 31)",
  " (in 'export_interpolate', line 34, column 6 to column 105)",
  " (in 'export_interpolate', line 33, column 11 to line 35, column 5)",
  " (in 'export_interpolate', line 32, column 6 to column 74)",
  " (in 'export_interpolate', line 31, column 22 to line 33, column 5)",
  " (in 'export_interpolate', line 31, column 4 to line 35, column 5)",
  " (in 'export_interpolate', line 30, column 20 to line 36, column 3)",
  " (in 'export_interpolate', line 30, column 2 to line 36, column 3)",
  " (in 'export_interpolate', line 37, column 2 to column 20)",
  " (in 'export_interpolate', line 27, column 107 to line 38, column 1)",
  " (in 'export_interpolate', line 42, column 9 to column 12)",
  " (in 'export_interpolate', line 42, column 14 to column 17)",
  " (in 'export_interpolate', line 42, column 2 to column 55)",
  " (in 'export_interpolate', line 43, column 9 to column 12)",
  " (in 'export_interpolate', line 43, column 2 to column 53)",
  " (in 'export_interpolate', line 44, column 9 to column 12)",
  " (in 'export_interpolate', line 44, column 14 to column 17)",
  " (in 'export_interpolate', line 44, column 2 to column 55)",
  " (in 'export_interpolate', line 46, column 2 to column 24)",
  " (in 'export_interpolate', line 40, column 45 to line 47, column 1)",
  " (in 'export_interpolate', line 50, column 9 to column 10)",
  " (in 'export_interpolate', line 50, column 11 to column 12)",
  " (in 'export_interpolate', line 50, column 2 to column 52)",
  " (in 'export_interpolate', line 51, column 2 to column 12)",
  " (in 'export_interpolate', line 49, column 22 to line 52, column 1)"};
template <typename T0__, typename T1__,
          stan::require_all_t<stan::is_stan_scalar<T0__>,
                              stan::is_col_vector<T1__>,
                              stan::is_vt_not_complex<T1__>>* = nullptr>
int findfirst(const T0__& t, const T1__& xt_arg__, std::ostream* pstream__);
template <typename T0__, typename T1__, typename T2__,
          stan::require_all_t<stan::is_stan_scalar<T0__>,
                              stan::is_col_vector<T1__>,
                              stan::is_vt_not_complex<T1__>,
                              stan::is_col_vector<T2__>,
                              stan::is_vt_not_complex<T2__>>* = nullptr>
stan::promote_args_t<T0__, stan::base_type_t<T1__>, stan::base_type_t<T2__>>
interpolate(const T0__& x, const T1__& xpt_arg__, const T2__& ypt_arg__,
            std::ostream* pstream__);
template <typename T0__, typename T2__, typename T3__, typename T4__,
          typename T5__, typename T7__,
          stan::require_all_t<stan::is_col_vector<T0__>,
                              stan::is_vt_not_complex<T0__>,
                              stan::is_stan_scalar<T2__>,
                              stan::is_eigen_matrix_dynamic<T3__>,
                              stan::is_vt_not_complex<T3__>,
                              stan::is_eigen_matrix_dynamic<T4__>,
                              stan::is_vt_not_complex<T4__>,
                              stan::is_col_vector<T5__>,
                              stan::is_vt_not_complex<T5__>,
                              stan::is_stan_scalar<T7__>>* = nullptr>
Eigen::Matrix<stan::promote_args_t<stan::base_type_t<T0__>, T2__,
                stan::base_type_t<T3__>, stan::base_type_t<T4__>,
                stan::base_type_t<T5__>, stan::promote_args_t<T7__>>,-1,-1>
exact_AD_long(const T0__& time_arg__, const int& N_time, const T2__& tacc,
              const T3__& E_arg__, const T4__& I_arg__, const T5__& U_arg__,
              const int& N_comp, const T7__& Cx, std::ostream* pstream__);
template <typename T0__, typename T1__,
          stan::require_all_t<stan::is_col_vector<T0__>,
                              stan::is_vt_not_complex<T0__>,
                              stan::is_eigen_matrix_dynamic<T1__>,
                              stan::is_vt_not_complex<T1__>>* = nullptr>
Eigen::Matrix<stan::promote_args_t<stan::base_type_t<T0__>,
                stan::base_type_t<T1__>>,-1,-1>
matrix_E(const T0__& ke_arg__, const T1__& k_arg__, const int& N_k,
         std::ostream* pstream__);
Eigen::Matrix<double,-1,-1> matrix_I(const int& k, std::ostream* pstream__);
template <typename T0__, typename T1__,
          stan::require_all_t<stan::is_stan_scalar<T0__>,
                              stan::is_col_vector<T1__>,
                              stan::is_vt_not_complex<T1__>>*>
int findfirst(const T0__& t, const T1__& xt_arg__, std::ostream* pstream__) {
  using local_scalar_t__ = stan::promote_args_t<T0__,
                             stan::base_type_t<T1__>>;
  int current_statement__ = 0;
  const auto& xt = stan::math::to_ref(xt_arg__);
  static constexpr bool propto__ = true;
  // suppress unused var warning
  (void) propto__;
  local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
  // suppress unused var warning
  (void) DUMMY_VAR__;
  try {
    int i = std::numeric_limits<int>::min();
    current_statement__ = 9;
    i = 0;
    current_statement__ = 21;
    if (stan::math::logical_eq(t, stan::math::max(xt))) {
      current_statement__ = 18;
      i = (stan::math::num_elements(xt) - 1);
      current_statement__ = 19;
      return i;
    } else {
      current_statement__ = 17;
      if ((stan::math::primitive_value(
             stan::math::logical_lt(t, stan::math::min(xt)))
          ||
          stan::math::primitive_value(
            stan::math::logical_gt(t, stan::math::max(xt))))) {
        current_statement__ = 15;
        return i;
      } else {
        current_statement__ = 12;
        while (stan::math::logical_gte(t,
                 stan::model::rvalue(xt, "xt",
                   stan::model::index_uni((i + 1))))) {
          current_statement__ = 10;
          i = (i + 1);
        }
        current_statement__ = 13;
        return i;
      }
    }
  } catch (const std::exception& e) {
    stan::lang::rethrow_located(e, locations_array__[current_statement__]);
  }
}
template <typename T0__, typename T1__, typename T2__,
          stan::require_all_t<stan::is_stan_scalar<T0__>,
                              stan::is_col_vector<T1__>,
                              stan::is_vt_not_complex<T1__>,
                              stan::is_col_vector<T2__>,
                              stan::is_vt_not_complex<T2__>>*>
stan::promote_args_t<T0__, stan::base_type_t<T1__>, stan::base_type_t<T2__>>
interpolate(const T0__& x, const T1__& xpt_arg__, const T2__& ypt_arg__,
            std::ostream* pstream__) {
  using local_scalar_t__ = stan::promote_args_t<T0__,
                             stan::base_type_t<T1__>,
                             stan::base_type_t<T2__>>;
  int current_statement__ = 0;
  const auto& xpt = stan::math::to_ref(xpt_arg__);
  const auto& ypt = stan::math::to_ref(ypt_arg__);
  static constexpr bool propto__ = true;
  // suppress unused var warning
  (void) propto__;
  local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
  // suppress unused var warning
  (void) DUMMY_VAR__;
  try {
    current_statement__ = 28;
    if ((stan::math::primitive_value(
           stan::math::logical_gte(x, stan::math::min(xpt)))
        &&
        stan::math::primitive_value(
          stan::math::logical_lte(x, stan::math::max(xpt))))) {
      int idx = std::numeric_limits<int>::min();
      current_statement__ = 25;
      idx = findfirst(x, xpt, pstream__);
      current_statement__ = 26;
      return (stan::model::rvalue(ypt, "ypt", stan::model::index_uni(idx)) +
             (((x -
             stan::model::rvalue(xpt, "xpt", stan::model::index_uni(idx))) *
             (stan::model::rvalue(ypt, "ypt",
                stan::model::index_uni((idx + 1)))
             - stan::model::rvalue(ypt, "ypt", stan::model::index_uni(idx))))
             /
             (stan::model::rvalue(xpt, "xpt",
                stan::model::index_uni((idx + 1)))
             -
             stan::model::rvalue(xpt, "xpt", stan::model::index_uni(idx)))));
    } else {
      current_statement__ = 23;
      return 0.0;
    }
  } catch (const std::exception& e) {
    stan::lang::rethrow_located(e, locations_array__[current_statement__]);
  }
}
template <typename T0__, typename T2__, typename T3__, typename T4__,
          typename T5__, typename T7__,
          stan::require_all_t<stan::is_col_vector<T0__>,
                              stan::is_vt_not_complex<T0__>,
                              stan::is_stan_scalar<T2__>,
                              stan::is_eigen_matrix_dynamic<T3__>,
                              stan::is_vt_not_complex<T3__>,
                              stan::is_eigen_matrix_dynamic<T4__>,
                              stan::is_vt_not_complex<T4__>,
                              stan::is_col_vector<T5__>,
                              stan::is_vt_not_complex<T5__>,
                              stan::is_stan_scalar<T7__>>*>
Eigen::Matrix<stan::promote_args_t<stan::base_type_t<T0__>, T2__,
                stan::base_type_t<T3__>, stan::base_type_t<T4__>,
                stan::base_type_t<T5__>, stan::promote_args_t<T7__>>,-1,-1>
exact_AD_long(const T0__& time_arg__, const int& N_time, const T2__& tacc,
              const T3__& E_arg__, const T4__& I_arg__, const T5__& U_arg__,
              const int& N_comp, const T7__& Cx, std::ostream* pstream__) {
  using local_scalar_t__ = stan::promote_args_t<stan::base_type_t<T0__>,
                             T2__, stan::base_type_t<T3__>,
                             stan::base_type_t<T4__>,
                             stan::base_type_t<T5__>,
                             stan::promote_args_t<T7__>>;
  int current_statement__ = 0;
  const auto& time = stan::math::to_ref(time_arg__);
  const auto& E = stan::math::to_ref(E_arg__);
  const auto& I = stan::math::to_ref(I_arg__);
  const auto& U = stan::math::to_ref(U_arg__);
  static constexpr bool propto__ = true;
  // suppress unused var warning
  (void) propto__;
  local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
  // suppress unused var warning
  (void) DUMMY_VAR__;
  try {
    current_statement__ = 30;
    stan::math::validate_non_negative_index("E_inv", "N_comp", N_comp);
    current_statement__ = 31;
    stan::math::validate_non_negative_index("E_inv", "N_comp", N_comp);
    Eigen::Matrix<local_scalar_t__,-1,-1> E_inv =
      Eigen::Matrix<local_scalar_t__,-1,-1>::Constant(N_comp, N_comp,
        DUMMY_VAR__);
    current_statement__ = 32;
    stan::model::assign(E_inv, stan::math::inverse(E),
      "assigning variable E_inv");
    current_statement__ = 33;
    stan::math::validate_non_negative_index("E_out", "N_comp", N_comp);
    current_statement__ = 34;
    stan::math::validate_non_negative_index("E_out", "N_time", N_time);
    Eigen::Matrix<local_scalar_t__,-1,-1> E_out =
      Eigen::Matrix<local_scalar_t__,-1,-1>::Constant(N_comp, N_time,
        DUMMY_VAR__);
    current_statement__ = 42;
    for (int i = 1; i <= N_time; ++i) {
      current_statement__ = 40;
      if (stan::math::logical_lt(
            stan::model::rvalue(time, "time", stan::model::index_uni(i)),
            tacc)) {
        current_statement__ = 38;
        stan::model::assign(E_out,
          stan::math::multiply(
            stan::math::multiply(
              stan::math::multiply(E_inv,
                stan::math::subtract(
                  stan::math::matrix_exp(
                    stan::math::multiply(
                      stan::model::rvalue(time, "time",
                        stan::model::index_uni(i)), E)), I)), U), Cx),
          "assigning variable E_out", stan::model::index_min_max(1, N_comp),
          stan::model::index_uni(i));
      } else {
        current_statement__ = 36;
        stan::model::assign(E_out,
          stan::math::multiply(
            stan::math::multiply(
              stan::math::multiply(E_inv,
                stan::math::subtract(
                  stan::math::matrix_exp(
                    stan::math::multiply(
                      stan::model::rvalue(time, "time",
                        stan::model::index_uni(i)), E)),
                  stan::math::matrix_exp(
                    stan::math::multiply(
                      (stan::model::rvalue(time, "time",
                         stan::model::index_uni(i)) - tacc), E)))), U), Cx),
          "assigning variable E_out", stan::model::index_min_max(1, N_comp),
          stan::model::index_uni(i));
      }
    }
    current_statement__ = 43;
    return stan::math::transpose(E_out);
  } catch (const std::exception& e) {
    stan::lang::rethrow_located(e, locations_array__[current_statement__]);
  }
}
template <typename T0__, typename T1__,
          stan::require_all_t<stan::is_col_vector<T0__>,
                              stan::is_vt_not_complex<T0__>,
                              stan::is_eigen_matrix_dynamic<T1__>,
                              stan::is_vt_not_complex<T1__>>*>
Eigen::Matrix<stan::promote_args_t<stan::base_type_t<T0__>,
                stan::base_type_t<T1__>>,-1,-1>
matrix_E(const T0__& ke_arg__, const T1__& k_arg__, const int& N_k,
         std::ostream* pstream__) {
  using local_scalar_t__ = stan::promote_args_t<stan::base_type_t<T0__>,
                             stan::base_type_t<T1__>>;
  int current_statement__ = 0;
  const auto& ke = stan::math::to_ref(ke_arg__);
  const auto& k = stan::math::to_ref(k_arg__);
  static constexpr bool propto__ = true;
  // suppress unused var warning
  (void) propto__;
  local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
  // suppress unused var warning
  (void) DUMMY_VAR__;
  try {
    current_statement__ = 45;
    stan::math::validate_non_negative_index("m", "N_k", N_k);
    current_statement__ = 46;
    stan::math::validate_non_negative_index("m", "N_k", N_k);
    Eigen::Matrix<local_scalar_t__,-1,-1> m =
      Eigen::Matrix<local_scalar_t__,-1,-1>::Constant(N_k, N_k, DUMMY_VAR__);
    current_statement__ = 47;
    stan::model::assign(m,
      stan::math::add_diag(k, stan::math::rep_vector(0, N_k)),
      "assigning variable m");
    current_statement__ = 48;
    stan::math::validate_non_negative_index("diag_k", "N_k", N_k);
    Eigen::Matrix<local_scalar_t__,-1,1> diag_k =
      Eigen::Matrix<local_scalar_t__,-1,1>::Constant(N_k, DUMMY_VAR__);
    current_statement__ = 49;
    stan::model::assign(diag_k,
      stan::math::subtract(stan::math::minus(ke),
        stan::math::multiply(m, stan::math::rep_vector(1, N_k))),
      "assigning variable diag_k");
    current_statement__ = 50;
    stan::math::validate_non_negative_index("matrix_E_rtn", "N_k", N_k);
    current_statement__ = 51;
    stan::math::validate_non_negative_index("matrix_E_rtn", "N_k", N_k);
    Eigen::Matrix<local_scalar_t__,-1,-1> matrix_E_rtn =
      Eigen::Matrix<local_scalar_t__,-1,-1>::Constant(N_k, N_k, DUMMY_VAR__);
    current_statement__ = 52;
    stan::model::assign(matrix_E_rtn, stan::math::add_diag(k, diag_k),
      "assigning variable matrix_E_rtn");
    current_statement__ = 53;
    return matrix_E_rtn;
  } catch (const std::exception& e) {
    stan::lang::rethrow_located(e, locations_array__[current_statement__]);
  }
}
Eigen::Matrix<double,-1,-1> matrix_I(const int& k, std::ostream* pstream__) {
  using local_scalar_t__ = double;
  int current_statement__ = 0;
  static constexpr bool propto__ = true;
  // suppress unused var warning
  (void) propto__;
  local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
  // suppress unused var warning
  (void) DUMMY_VAR__;
  try {
    current_statement__ = 55;
    stan::math::validate_non_negative_index("I", "k", k);
    current_statement__ = 56;
    stan::math::validate_non_negative_index("I", "k", k);
    Eigen::Matrix<local_scalar_t__,-1,-1> I =
      Eigen::Matrix<local_scalar_t__,-1,-1>::Constant(k, k, DUMMY_VAR__);
    current_statement__ = 57;
    stan::model::assign(I,
      stan::math::add_diag(stan::math::rep_matrix(0, k, k), 1),
      "assigning variable I");
    current_statement__ = 58;
    return I;
  } catch (const std::exception& e) {
    stan::lang::rethrow_located(e, locations_array__[current_statement__]);
  }
}
#include <stan_meta_header.hpp>
class model_export_interpolate final : public model_base_crtp<model_export_interpolate> {
private:
  double x;
  int N;
  Eigen::Matrix<double,-1,1> xpt_data__;
  Eigen::Matrix<double,-1,1> ypt_data__;
  Eigen::Map<Eigen::Matrix<double,-1,1>> xpt{nullptr, 0};
  Eigen::Map<Eigen::Matrix<double,-1,1>> ypt{nullptr, 0};
public:
  ~model_export_interpolate() {}
  model_export_interpolate(stan::io::var_context& context__, unsigned int
                           random_seed__ = 0, std::ostream*
                           pstream__ = nullptr) : model_base_crtp(0) {
    int current_statement__ = 0;
    using local_scalar_t__ = double;
    boost::ecuyer1988 base_rng__ =
      stan::services::util::create_rng(random_seed__, 0);
    // suppress unused var warning
    (void) base_rng__;
    static constexpr const char* function__ =
      "model_export_interpolate_namespace::model_export_interpolate";
    // suppress unused var warning
    (void) function__;
    local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
    // suppress unused var warning
    (void) DUMMY_VAR__;
    try {
      int pos__ = std::numeric_limits<int>::min();
      pos__ = 1;
      current_statement__ = 3;
      context__.validate_dims("data initialization", "x", "double",
        std::vector<size_t>{});
      x = std::numeric_limits<double>::quiet_NaN();
      current_statement__ = 3;
      x = context__.vals_r("x")[(1 - 1)];
      current_statement__ = 4;
      context__.validate_dims("data initialization", "N", "int",
        std::vector<size_t>{});
      N = std::numeric_limits<int>::min();
      current_statement__ = 4;
      N = context__.vals_i("N")[(1 - 1)];
      current_statement__ = 5;
      stan::math::validate_non_negative_index("xpt", "N", N);
      current_statement__ = 6;
      context__.validate_dims("data initialization", "xpt", "double",
        std::vector<size_t>{static_cast<size_t>(N)});
      xpt_data__ = Eigen::Matrix<double,-1,1>::Constant(N,
                     std::numeric_limits<double>::quiet_NaN());
      new (&xpt) Eigen::Map<Eigen::Matrix<double,-1,1>>(xpt_data__.data(), N);
      {
        std::vector<local_scalar_t__> xpt_flat__;
        current_statement__ = 6;
        xpt_flat__ = context__.vals_r("xpt");
        current_statement__ = 6;
        pos__ = 1;
        current_statement__ = 6;
        for (int sym1__ = 1; sym1__ <= N; ++sym1__) {
          current_statement__ = 6;
          stan::model::assign(xpt, xpt_flat__[(pos__ - 1)],
            "assigning variable xpt", stan::model::index_uni(sym1__));
          current_statement__ = 6;
          pos__ = (pos__ + 1);
        }
      }
      current_statement__ = 7;
      stan::math::validate_non_negative_index("ypt", "N", N);
      current_statement__ = 8;
      context__.validate_dims("data initialization", "ypt", "double",
        std::vector<size_t>{static_cast<size_t>(N)});
      ypt_data__ = Eigen::Matrix<double,-1,1>::Constant(N,
                     std::numeric_limits<double>::quiet_NaN());
      new (&ypt) Eigen::Map<Eigen::Matrix<double,-1,1>>(ypt_data__.data(), N);
      {
        std::vector<local_scalar_t__> ypt_flat__;
        current_statement__ = 8;
        ypt_flat__ = context__.vals_r("ypt");
        current_statement__ = 8;
        pos__ = 1;
        current_statement__ = 8;
        for (int sym1__ = 1; sym1__ <= N; ++sym1__) {
          current_statement__ = 8;
          stan::model::assign(ypt, ypt_flat__[(pos__ - 1)],
            "assigning variable ypt", stan::model::index_uni(sym1__));
          current_statement__ = 8;
          pos__ = (pos__ + 1);
        }
      }
    } catch (const std::exception& e) {
      stan::lang::rethrow_located(e, locations_array__[current_statement__]);
    }
    num_params_r__ = 0U;
  }
  inline std::string model_name() const final {
    return "model_export_interpolate";
  }
  inline std::vector<std::string> model_compile_info() const noexcept {
    return std::vector<std::string>{"stanc_version = stanc3 v2.32.2",
             "stancflags = --allow-undefined"};
  }
  template <bool propto__, bool jacobian__, typename VecR, typename VecI,
            stan::require_vector_like_t<VecR>* = nullptr,
            stan::require_vector_like_vt<std::is_integral, VecI>* = nullptr>
  inline stan::scalar_type_t<VecR>
  log_prob_impl(VecR& params_r__, VecI& params_i__, std::ostream*
                pstream__ = nullptr) const {
    using T__ = stan::scalar_type_t<VecR>;
    using local_scalar_t__ = T__;
    T__ lp__(0.0);
    stan::math::accumulator<T__> lp_accum__;
    stan::io::deserializer<local_scalar_t__> in__(params_r__, params_i__);
    int current_statement__ = 0;
    local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
    // suppress unused var warning
    (void) DUMMY_VAR__;
    static constexpr const char* function__ =
      "model_export_interpolate_namespace::log_prob";
    // suppress unused var warning
    (void) function__;
    try {
      
    } catch (const std::exception& e) {
      stan::lang::rethrow_located(e, locations_array__[current_statement__]);
    }
    lp_accum__.add(lp__);
    return lp_accum__.sum();
  }
  template <typename RNG, typename VecR, typename VecI, typename VecVar,
            stan::require_vector_like_vt<std::is_floating_point,
            VecR>* = nullptr, stan::require_vector_like_vt<std::is_integral,
            VecI>* = nullptr, stan::require_vector_vt<std::is_floating_point,
            VecVar>* = nullptr>
  inline void
  write_array_impl(RNG& base_rng__, VecR& params_r__, VecI& params_i__,
                   VecVar& vars__, const bool
                   emit_transformed_parameters__ = true, const bool
                   emit_generated_quantities__ = true, std::ostream*
                   pstream__ = nullptr) const {
    using local_scalar_t__ = double;
    stan::io::deserializer<local_scalar_t__> in__(params_r__, params_i__);
    stan::io::serializer<local_scalar_t__> out__(vars__);
    static constexpr bool propto__ = true;
    // suppress unused var warning
    (void) propto__;
    double lp__ = 0.0;
    // suppress unused var warning
    (void) lp__;
    int current_statement__ = 0;
    stan::math::accumulator<double> lp_accum__;
    local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
    // suppress unused var warning
    (void) DUMMY_VAR__;
    constexpr bool jacobian__ = false;
    static constexpr const char* function__ =
      "model_export_interpolate_namespace::write_array";
    // suppress unused var warning
    (void) function__;
    try {
      if (stan::math::logical_negation(
            (stan::math::primitive_value(emit_transformed_parameters__) ||
            stan::math::primitive_value(emit_generated_quantities__)))) {
        return ;
      }
      if (stan::math::logical_negation(emit_generated_quantities__)) {
        return ;
      }
      double y = std::numeric_limits<double>::quiet_NaN();
      current_statement__ = 2;
      y = interpolate(x, xpt, ypt, pstream__);
      out__.write(y);
    } catch (const std::exception& e) {
      stan::lang::rethrow_located(e, locations_array__[current_statement__]);
    }
  }
  template <typename VecVar, typename VecI,
            stan::require_vector_t<VecVar>* = nullptr,
            stan::require_vector_like_vt<std::is_integral, VecI>* = nullptr>
  inline void
  unconstrain_array_impl(const VecVar& params_r__, const VecI& params_i__,
                         VecVar& vars__, std::ostream* pstream__ = nullptr) const {
    using local_scalar_t__ = double;
    stan::io::deserializer<local_scalar_t__> in__(params_r__, params_i__);
    stan::io::serializer<local_scalar_t__> out__(vars__);
    int current_statement__ = 0;
    local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
    // suppress unused var warning
    (void) DUMMY_VAR__;
    try {
      int pos__ = std::numeric_limits<int>::min();
      pos__ = 1;
    } catch (const std::exception& e) {
      stan::lang::rethrow_located(e, locations_array__[current_statement__]);
    }
  }
  template <typename VecVar, stan::require_vector_t<VecVar>* = nullptr>
  inline void
  transform_inits_impl(const stan::io::var_context& context__, VecVar&
                       vars__, std::ostream* pstream__ = nullptr) const {
    using local_scalar_t__ = double;
    stan::io::serializer<local_scalar_t__> out__(vars__);
    int current_statement__ = 0;
    local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
    // suppress unused var warning
    (void) DUMMY_VAR__;
    try {
      int pos__ = std::numeric_limits<int>::min();
      pos__ = 1;
    } catch (const std::exception& e) {
      stan::lang::rethrow_located(e, locations_array__[current_statement__]);
    }
  }
  inline void
  get_param_names(std::vector<std::string>& names__, const bool
                  emit_transformed_parameters__ = true, const bool
                  emit_generated_quantities__ = true) const {
    names__ = std::vector<std::string>{};
    if (emit_transformed_parameters__) {}
    if (emit_generated_quantities__) {
      std::vector<std::string> temp{"y"};
      names__.reserve(names__.size() + temp.size());
      names__.insert(names__.end(), temp.begin(), temp.end());
    }
  }
  inline void
  get_dims(std::vector<std::vector<size_t>>& dimss__, const bool
           emit_transformed_parameters__ = true, const bool
           emit_generated_quantities__ = true) const {
    dimss__ = std::vector<std::vector<size_t>>{};
    if (emit_transformed_parameters__) {}
    if (emit_generated_quantities__) {
      std::vector<std::vector<size_t>> temp{std::vector<size_t>{}};
      dimss__.reserve(dimss__.size() + temp.size());
      dimss__.insert(dimss__.end(), temp.begin(), temp.end());
    }
  }
  inline void
  constrained_param_names(std::vector<std::string>& param_names__, bool
                          emit_transformed_parameters__ = true, bool
                          emit_generated_quantities__ = true) const final {
    if (emit_transformed_parameters__) {}
    if (emit_generated_quantities__) {
      param_names__.emplace_back(std::string() + "y");
    }
  }
  inline void
  unconstrained_param_names(std::vector<std::string>& param_names__, bool
                            emit_transformed_parameters__ = true, bool
                            emit_generated_quantities__ = true) const final {
    if (emit_transformed_parameters__) {}
    if (emit_generated_quantities__) {
      param_names__.emplace_back(std::string() + "y");
    }
  }
  inline std::string get_constrained_sizedtypes() const {
    return std::string("[{\"name\":\"y\",\"type\":{\"name\":\"real\"},\"block\":\"generated_quantities\"}]");
  }
  inline std::string get_unconstrained_sizedtypes() const {
    return std::string("[{\"name\":\"y\",\"type\":{\"name\":\"real\"},\"block\":\"generated_quantities\"}]");
  }
  // Begin method overload boilerplate
  template <typename RNG> inline void
  write_array(RNG& base_rng, Eigen::Matrix<double,-1,1>& params_r,
              Eigen::Matrix<double,-1,1>& vars, const bool
              emit_transformed_parameters = true, const bool
              emit_generated_quantities = true, std::ostream*
              pstream = nullptr) const {
    const size_t num_params__ = 0;
    const size_t num_transformed = emit_transformed_parameters * (0);
    const size_t num_gen_quantities = emit_generated_quantities * (1);
    const size_t num_to_write = num_params__ + num_transformed +
      num_gen_quantities;
    std::vector<int> params_i;
    vars = Eigen::Matrix<double,-1,1>::Constant(num_to_write,
             std::numeric_limits<double>::quiet_NaN());
    write_array_impl(base_rng, params_r, params_i, vars,
      emit_transformed_parameters, emit_generated_quantities, pstream);
  }
  template <typename RNG> inline void
  write_array(RNG& base_rng, std::vector<double>& params_r, std::vector<int>&
              params_i, std::vector<double>& vars, bool
              emit_transformed_parameters = true, bool
              emit_generated_quantities = true, std::ostream*
              pstream = nullptr) const {
    const size_t num_params__ = 0;
    const size_t num_transformed = emit_transformed_parameters * (0);
    const size_t num_gen_quantities = emit_generated_quantities * (1);
    const size_t num_to_write = num_params__ + num_transformed +
      num_gen_quantities;
    vars = std::vector<double>(num_to_write,
             std::numeric_limits<double>::quiet_NaN());
    write_array_impl(base_rng, params_r, params_i, vars,
      emit_transformed_parameters, emit_generated_quantities, pstream);
  }
  template <bool propto__, bool jacobian__, typename T_> inline T_
  log_prob(Eigen::Matrix<T_,-1,1>& params_r, std::ostream* pstream = nullptr) const {
    Eigen::Matrix<int,-1,1> params_i;
    return log_prob_impl<propto__, jacobian__>(params_r, params_i, pstream);
  }
  template <bool propto__, bool jacobian__, typename T_> inline T_
  log_prob(std::vector<T_>& params_r, std::vector<int>& params_i,
           std::ostream* pstream = nullptr) const {
    return log_prob_impl<propto__, jacobian__>(params_r, params_i, pstream);
  }
  inline void
  transform_inits(const stan::io::var_context& context,
                  Eigen::Matrix<double,-1,1>& params_r, std::ostream*
                  pstream = nullptr) const final {
    std::vector<double> params_r_vec(params_r.size());
    std::vector<int> params_i;
    transform_inits(context, params_i, params_r_vec, pstream);
    params_r = Eigen::Map<Eigen::Matrix<double,-1,1>>(params_r_vec.data(),
                 params_r_vec.size());
  }
  inline void
  transform_inits(const stan::io::var_context& context, std::vector<int>&
                  params_i, std::vector<double>& vars, std::ostream*
                  pstream__ = nullptr) const {
    vars.resize(num_params_r__);
    transform_inits_impl(context, vars, pstream__);
  }
  inline void
  unconstrain_array(const std::vector<double>& params_constrained,
                    std::vector<double>& params_unconstrained, std::ostream*
                    pstream = nullptr) const {
    const std::vector<int> params_i;
    params_unconstrained = std::vector<double>(num_params_r__,
                             std::numeric_limits<double>::quiet_NaN());
    unconstrain_array_impl(params_constrained, params_i,
      params_unconstrained, pstream);
  }
  inline void
  unconstrain_array(const Eigen::Matrix<double,-1,1>& params_constrained,
                    Eigen::Matrix<double,-1,1>& params_unconstrained,
                    std::ostream* pstream = nullptr) const {
    const std::vector<int> params_i;
    params_unconstrained = Eigen::Matrix<double,-1,1>::Constant(num_params_r__,
                             std::numeric_limits<double>::quiet_NaN());
    unconstrain_array_impl(params_constrained, params_i,
      params_unconstrained, pstream);
  }
};
}
using stan_model = model_export_interpolate_namespace::model_export_interpolate;
#ifndef USING_R
// Boilerplate
stan::model::model_base&
new_model(stan::io::var_context& data_context, unsigned int seed,
          std::ostream* msg_stream) {
  stan_model* m = new stan_model(data_context, seed, msg_stream);
  return *m;
}
stan::math::profile_map& get_stan_profile_data() {
  return model_export_interpolate_namespace::profiles__;
}
#endif
#endif
