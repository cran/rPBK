int findfirst(real t, vector xt) {
  int i = 0 ;
  if(t == max(xt)){
    i = num_elements(xt) - 1 ;
    return i ;
  } else if(t < min(xt) || t > max(xt)){
    return i ;
  } else {
    while (t >= xt[i+1]){
      i = i+1 ;
    }
    return i ;
  }
}

real interpolate(real x, vector xpt, vector ypt){
  if(x >= min(xpt) && x <= max(xpt)){
    int idx = findfirst(x, xpt) ;
    return ypt[idx] + (x - xpt[idx]) * (ypt[idx+1] - ypt[idx]) / (xpt[idx+1] - xpt[idx]) ;
  } else{
    return 0.0 ;
  }
}

matrix exact_AD_long(vector time, int N_time, real tacc, matrix E, matrix I, vector U, int N_comp, real Cx){
  matrix[N_comp,N_comp] E_inv = inverse(E) ;
  matrix[N_comp,N_time] E_out ;
  for(i in 1:N_time){
    if(time[i] < tacc){
      E_out[1:N_comp,i] = E_inv * (matrix_exp(time[i] * E) - I) * U * Cx ;
    } else {
      E_out[1:N_comp,i] = E_inv * (matrix_exp(time[i] * E) - matrix_exp((time[i] - tacc) * E)) * U * Cx ;
    }
  }
  return( E_out' ) ;
}

matrix matrix_E(vector ke, matrix k, int N_k){

  matrix[N_k, N_k] m = add_diag(k, rep_vector(0,N_k)) ;
  vector[N_k] diag_k = - ke - m * rep_vector(1,N_k) ;
  matrix[N_k, N_k] matrix_E = add_diag(k, diag_k) ;

  return(matrix_E) ;
}

matrix matrix_I(int k){
  matrix[k,k] I = add_diag(rep_matrix(0, k, k), 1) ;
  return(I);
}
