/*
 * 
 * Copyright (c) Toon Knapen & Kresimir Fresl 2003
 *
 * Distributed under the Boost Software License, Version 1.0.
 * (See accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 *
 * KF acknowledges the support of the Faculty of Civil Engineering, 
 * University of Zagreb, Croatia.
 *
 */

#ifndef BOOST_NUMERIC_BINDINGS_LAPACK_LAPACK_H
#define BOOST_NUMERIC_BINDINGS_LAPACK_LAPACK_H

#include <boost/numeric/bindings/traits/type.h>
#include <boost/numeric/bindings/lapack/lapack_names.h>

#ifndef BOOST_NUMERIC_BINDINGS_NO_STRUCTURE_CHECK 
#  define BOOST_NUMERIC_BINDINGS_FORTRAN
#endif 

extern "C" {

  /********************************************************************/
  /*                        linear systems                            */
  /********************************************************************/

  /* general */

  void _cdecl LAPACK_SGESV (int const* n, int const* nrhs, 
                     float* a, int const* lda, int* ipiv, 
                     float* b, int const* ldb, int* info);
  void _cdecl LAPACK_DGESV (int const* n, int const* nrhs, 
                     double* a, int const* lda, int* ipiv, 
                     double* b, int const* ldb, int* info);
  void _cdecl LAPACK_CGESV (int const* n, int const* nrhs,
                     fcomplex_t* a, int const* lda, int* ipiv, 
                     fcomplex_t* b, int const* ldb, int* info);
  void _cdecl LAPACK_ZGESV (int const* n, int const* nrhs,
                     dcomplex_t* a, int const* lda, int* ipiv, 
                     dcomplex_t* b, int const* ldb, int* info);

  void _cdecl LAPACK_SGETRF (int const* n, int const* nrhs, 
                      float* a, int const* lda, int* ipiv, int* info);
  void _cdecl LAPACK_DGETRF (int const* n, int const* nrhs, 
                      double* a, int const* lda, int* ipiv, int* info);
  void _cdecl LAPACK_CGETRF (int const* n, int const* nrhs,
                      fcomplex_t* a, int const* lda,
                      int* ipiv, int* info);
  void _cdecl LAPACK_ZGETRF (int const* n, int const* nrhs,
                      dcomplex_t* a, int const* lda,
                      int* ipiv, int* info);

  void _cdecl LAPACK_SGETRS (char const* trans, int const* n, int const* nrhs, 
                      float const* a, int const* lda, int const* ipiv, 
                      float* b, int const* ldb, int* info);
  void _cdecl LAPACK_DGETRS (char const* trans, int const* n, int const* nrhs, 
                      double const* a, int const* lda, int const* ipiv, 
                      double* b, int const* ldb, int* info);
  void _cdecl LAPACK_CGETRS (char const* trans, int const* n, int const* nrhs,
                      fcomplex_t const* a, int const* lda, int const* ipiv, 
                      fcomplex_t* b, int const* ldb, int* info);
  void _cdecl LAPACK_ZGETRS (char const* trans, int const* n, int const* nrhs,
                      dcomplex_t const* a, int const* lda, int const* ipiv, 
                      dcomplex_t* b, int const* ldb, int* info);

  void _cdecl LAPACK_SGETRI (int const* n, float* a, int const* lda,	int const* ipiv, 
		      float* work, int const* lwork, int* info);
  void _cdecl LAPACK_DGETRI (int const* n, double* a, int const* lda,	int const* ipiv, 
		      double* work, int const* lwork, int* info);
  void _cdecl LAPACK_CGETRI (int const* n, fcomplex_t* a, int const* lda,	int const* ipiv, 
		      fcomplex_t* work, int const* lwork, int* info);
  void _cdecl LAPACK_ZGETRI (int const* n, dcomplex_t* a, int const* lda,	int const* ipiv, 
		      dcomplex_t* work, int const* lwork, int* info);

  /* symmetric/Hermitian positive definite */

  void _cdecl LAPACK_SPOSV (char const* uplo, int const* n, int const* nrhs, 
                     float* a, int const* lda, 
                     float* b, int const* ldb, int* info);
  void _cdecl LAPACK_DPOSV (char const* uplo, int const* n, int const* nrhs, 
                     double* a, int const* lda, 
                     double* b, int const* ldb, int* info);
  void _cdecl LAPACK_CPOSV (char const* uplo, int const* n, int const* nrhs,
                     fcomplex_t* a, int const* lda,
                     fcomplex_t* b, int const* ldb, int* info);
  void _cdecl LAPACK_ZPOSV (char const* uplo, int const* n, int const* nrhs,
                     dcomplex_t* a, int const* lda,
                     dcomplex_t* b, int const* ldb, int* info);

  void _cdecl LAPACK_SPOTRF (char const* uplo, int const* n, 
                      float* a, int const* lda, int* info);
  void _cdecl LAPACK_DPOTRF (char const* uplo, int const* n, 
                      double* a, int const* lda, int* info);
  void _cdecl LAPACK_CPOTRF (char const* uplo, int const* n, 
                      fcomplex_t* a, int const* lda, int* info);
  void _cdecl LAPACK_ZPOTRF (char const* uplo, int const* n, 
                      dcomplex_t* a, int const* lda, int* info);

  void _cdecl LAPACK_SPOTRS (char const* uplo, int const* n, int const* nrhs, 
                      float const* a, int const* lda, 
                      float* b, int const* ldb, int* info);
  void _cdecl LAPACK_DPOTRS (char const* uplo, int const* n, int const* nrhs, 
                      double const* a, int const* lda, 
                      double* b, int const* ldb, int* info);
  void _cdecl LAPACK_CPOTRS (char const* uplo, int const* n, int const* nrhs,
                      fcomplex_t const* a, int const* lda,
                      fcomplex_t* b, int const* ldb, int* info);
  void _cdecl LAPACK_ZPOTRS (char const* uplo, int const* n, int const* nrhs,
                      dcomplex_t const* a, int const* lda,
                      dcomplex_t* b, int const* ldb, int* info);


  /* symmetric/Hermitian positive definite in packed storage */

  void _cdecl LAPACK_SPPSV (char const* uplo, int const* n, int const* nrhs, 
                     float* ap, float* b, int const* ldb, int* info);
  void _cdecl LAPACK_DPPSV (char const* uplo, int const* n, int const* nrhs, 
                     double* ap, double* b, int const* ldb, int* info);
  void _cdecl LAPACK_CPPSV (char const* uplo, int const* n, int const* nrhs,
                     fcomplex_t* ap, fcomplex_t* b, int const* ldb, int* info);
  void _cdecl LAPACK_ZPPSV (char const* uplo, int const* n, int const* nrhs,
                     dcomplex_t* ap, dcomplex_t* b, int const* ldb, int* info);

  void _cdecl LAPACK_SPPTRF (char const* uplo, int const* n, float* ap, int* info);
  void _cdecl LAPACK_DPPTRF (char const* uplo, int const* n, double* ap, int* info);
  void _cdecl LAPACK_CPPTRF (char const* uplo, int const* n, 
                      fcomplex_t* ap, int* info);
  void _cdecl LAPACK_ZPPTRF (char const* uplo, int const* n, 
                      dcomplex_t* ap, int* info);

  void _cdecl LAPACK_SPPTRS (char const* uplo, int const* n, int const* nrhs, 
                      float const* ap, float* b, int const* ldb, int* info);
  void _cdecl LAPACK_DPPTRS (char const* uplo, int const* n, int const* nrhs, 
                      double const* ap, double* b, int const* ldb, int* info);
  void _cdecl LAPACK_CPPTRS (char const* uplo, int const* n, int const* nrhs,
                      fcomplex_t const* ap, 
                      fcomplex_t* b, int const* ldb, int* info);
  void _cdecl LAPACK_ZPPTRS (char const* uplo, int const* n, int const* nrhs,
                      dcomplex_t const* ap, 
                      dcomplex_t* b, int const* ldb, int* info);

  void _cdecl LAPACK_SPPTRI (char const* uplo, int const* n, float* ap, int* info);
  void _cdecl LAPACK_DPPTRI (char const* uplo, int const* n, double* ap, int* info);
  void _cdecl LAPACK_CPPTRI (char const* uplo, int const* n, 
                      fcomplex_t* ap, int* info);
  void _cdecl LAPACK_ZPPTRI (char const* uplo, int const* n, 
                      dcomplex_t* ap, int* info);

  /* symmetric/Hermitian positive definite tridiagonal */

  void _cdecl LAPACK_SPTSV (int const* N, int const* NRHS, float* D, float* E
                    , float* B, int const* LDB, int* INFO
                    );
  void _cdecl LAPACK_DPTSV (int const* N, int const* NRHS, double* D, double* E
                    , double* B, int const* LDB, int* INFO
                    );
  void _cdecl LAPACK_CPTSV (int const* N, int const* NRHS, float* D, fcomplex_t* E
                    , fcomplex_t* B, int const* LDB, int* INFO
                    );
  void _cdecl LAPACK_ZPTSV (int const* N, int const* NRHS, double* D, dcomplex_t* E
                    , dcomplex_t* B, int const* LDB, int* INFO
                    );

  void _cdecl LAPACK_SPTTRF ( int const* n, float* d, float* e, int* info);
  void _cdecl LAPACK_DPTTRF ( int const* n, double* d, double* e, int* info);
  void _cdecl LAPACK_CPTTRF ( int const* n, float* d, fcomplex_t* e, int* info);
  void _cdecl LAPACK_ZPTTRF ( int const* n, double* d, dcomplex_t* e, int* info);

  void _cdecl LAPACK_SPTTRS ( int const* n, int const* nrhs, 
                      float const* d, float const* e,
                      float* b, int const* ldb, int* info);
  void _cdecl LAPACK_DPTTRS ( int const* n, int const* nrhs, 
                      double const* d, double const* e,
                      double* b, int const* ldb, int* info);
  void _cdecl LAPACK_CPTTRS (char const* uplo, int const* n, int const* nrhs,
                      float const* d, fcomplex_t const* e,
                      fcomplex_t* b, int const* ldb, int* info);
  void _cdecl LAPACK_ZPTTRS (char const* uplo, int const* n, int const* nrhs,
                      double const* d, dcomplex_t const* e,
                      dcomplex_t* b, int const* ldb, int* info);



  /* symmetric/Hermitian indefinite and complex symmetric */

  void _cdecl LAPACK_SSYSV (char const* uplo, int const* n, int const* nrhs, 
                     float* a, int const* lda, int* ipiv, 
                     float* b, int const* ldb, 
                     float* w, int const* lw, int* info);
  void _cdecl LAPACK_DSYSV (char const* uplo, int const* n, int const* nrhs, 
                     double* a, int const* lda, int* ipiv, 
                     double* b, int const* ldb, 
                     double* w, int const* lw, int* info);
  void _cdecl LAPACK_CSYSV (char const* uplo, int const* n, int const* nrhs,
                     fcomplex_t* a, int const* lda, int* ipiv, 
                     fcomplex_t* b, int const* ldb, 
                     fcomplex_t* w, int const* lw, int* info);
  void _cdecl LAPACK_ZSYSV (char const* uplo, int const* n, int const* nrhs,
                     dcomplex_t* a, int const* lda, int* ipiv, 
                     dcomplex_t* b, int const* ldb, 
                     dcomplex_t* w, int const* lw, int* info);

  void _cdecl LAPACK_CHESV (char const* uplo, int const* n, int const* nrhs,
                     fcomplex_t* a, int const* lda, int* ipiv, 
                     fcomplex_t* b, int const* ldb, 
                     fcomplex_t* w, int const* lw, int* info);
  void _cdecl LAPACK_ZHESV (char const* uplo, int const* n, int const* nrhs,
                     dcomplex_t* a, int const* lda, int* ipiv, 
                     dcomplex_t* b, int const* ldb, 
                     dcomplex_t* w, int const* lw, int* info);

  void _cdecl LAPACK_SSYTRF (char const* uplo, int const* n, 
                      float* a, int const* lda, int* ipiv, 
                      float* w, int const* lw, int* info);
  void _cdecl LAPACK_DSYTRF (char const* uplo, int const* n, 
                      double* a, int const* lda, int* ipiv, 
                      double* w, int const* lw, int* info);
  void _cdecl LAPACK_CSYTRF (char const* uplo, int const* n, 
                      fcomplex_t* a, int const* lda, int* ipiv, 
                      fcomplex_t* w, int const* lw, int* info);
  void _cdecl LAPACK_ZSYTRF (char const* uplo, int const* n, 
                      dcomplex_t* a, int const* lda, int* ipiv, 
                      dcomplex_t* w, int const* lw, int* info);

  void _cdecl LAPACK_CHETRF (char const* uplo, int const* n, 
                      fcomplex_t* a, int const* lda, int* ipiv, 
                      fcomplex_t* w, int const* lw, int* info);
  void _cdecl LAPACK_ZHETRF (char const* uplo, int const* n, 
                      dcomplex_t* a, int const* lda, int* ipiv, 
                      dcomplex_t* w, int const* lw, int* info);

  void _cdecl LAPACK_SSYTRS (char const* uplo, int const* n, int const* nrhs, 
                      float const* a, int const* lda, int const* ipiv, 
                      float* b, int const* ldb, int* info);
  void _cdecl LAPACK_DSYTRS (char const* uplo, int const* n, int const* nrhs, 
                      double const* a, int const* lda, int const* ipiv, 
                      double* b, int const* ldb, int* info);
  void _cdecl LAPACK_CSYTRS (char const* uplo, int const* n, int const* nrhs,
                      fcomplex_t const* a, int const* lda, int const* ipiv, 
                      fcomplex_t* b, int const* ldb, int* info);
  void _cdecl LAPACK_ZSYTRS (char const* uplo, int const* n, int const* nrhs,
                      dcomplex_t const* a, int const* lda, int const* ipiv, 
                      dcomplex_t* b, int const* ldb, int* info);

  void _cdecl LAPACK_SSYTRI (char const* uplo, int const* n, float* a, 
		      int const* lda, int const* ipiv, float* work, 
		      int* info);
  void _cdecl LAPACK_DSYTRI (char const* uplo, int const* n, double* a, 
		      int const* lda, int const* ipiv, double* work, 
		      int* info);
  void _cdecl LAPACK_CSYTRI (char const* uplo, int const* n, fcomplex_t* a, 
		      int const* lda, int const* ipiv, fcomplex_t* work, 
		      int* info);
  void _cdecl LAPACK_ZSYTRI (char const* uplo, int const* n, dcomplex_t* a, 
		      int const* lda, int const* ipiv, dcomplex_t* work, 
		      int* info);
 
  void _cdecl LAPACK_CHETRS (char const* uplo, int const* n, int const* nrhs,
                      fcomplex_t const* a, int const* lda, int const* ipiv, 
                      fcomplex_t* b, int const* ldb, int* info);
  void _cdecl LAPACK_ZHETRS (char const* uplo, int const* n, int const* nrhs,
                      dcomplex_t const* a, int const* lda, int const* ipiv, 
                      dcomplex_t* b, int const* ldb, int* info);


  /* symmetric/Hermitian indefinite and complex symmetric in packed storage */

  void _cdecl LAPACK_SSPSV (char const* uplo, int const* n, int const* nrhs, 
                     float* ap, int* ipiv, 
                     float* b, int const* ldb, int* info);
  void _cdecl LAPACK_DSPSV (char const* uplo, int const* n, int const* nrhs, 
                     double* ap, int* ipiv, 
                     double* b, int const* ldb, int* info);
  void _cdecl LAPACK_CSPSV (char const* uplo, int const* n, int const* nrhs,
                     fcomplex_t* ap, int* ipiv, 
                     fcomplex_t* b, int const* ldb, int* info);
  void _cdecl LAPACK_ZSPSV (char const* uplo, int const* n, int const* nrhs,
                     dcomplex_t* ap, int* ipiv, 
                     dcomplex_t* b, int const* ldb, int* info);

  void _cdecl LAPACK_CHPSV (char const* uplo, int const* n, int const* nrhs,
                     fcomplex_t* ap, int* ipiv, 
                     fcomplex_t* b, int const* ldb, int* info);
  void _cdecl LAPACK_ZHPSV (char const* uplo, int const* n, int const* nrhs,
                     dcomplex_t* ap, int* ipiv, 
                     dcomplex_t* b, int const* ldb, int* info);

  void _cdecl LAPACK_SSPTRF (char const* uplo, int const* n, 
                      float* ap, int* ipiv, int* info);
  void _cdecl LAPACK_DSPTRF (char const* uplo, int const* n, 
                      double* ap, int* ipiv, int* info);
  void _cdecl LAPACK_CSPTRF (char const* uplo, int const* n, 
                      fcomplex_t* ap, int* ipiv, int* info);
  void _cdecl LAPACK_ZSPTRF (char const* uplo, int const* n, 
                      dcomplex_t* ap, int* ipiv, int* info);

  void _cdecl LAPACK_CHPTRF (char const* uplo, int const* n, 
                      fcomplex_t* ap, int* ipiv, int* info);
  void _cdecl LAPACK_ZHPTRF (char const* uplo, int const* n, 
                      dcomplex_t* ap, int* ipiv, int* info);

  void _cdecl LAPACK_SSPTRS (char const* uplo, int const* n, int const* nrhs, 
                      float const* ap, int const* ipiv, 
                      float* b, int const* ldb, int* info);
  void _cdecl LAPACK_DSPTRS (char const* uplo, int const* n, int const* nrhs, 
                      double const* ap, int const* ipiv, 
                      double* b, int const* ldb, int* info);
  void _cdecl LAPACK_CSPTRS (char const* uplo, int const* n, int const* nrhs,
                      fcomplex_t const* ap, int const* ipiv, 
                      fcomplex_t* b, int const* ldb, int* info);
  void _cdecl LAPACK_ZSPTRS (char const* uplo, int const* n, int const* nrhs,
                      dcomplex_t const* ap, int const* ipiv, 
                      dcomplex_t* b, int const* ldb, int* info);

  void _cdecl LAPACK_SSPTRI (char const* uplo, int const* n, float const* ap, 
		      int const* ipiv, float* work, int* info);
  void _cdecl LAPACK_DSPTRI (char const* uplo, int const* n, double const* ap, 
		      int const* ipiv, double* work, int* info);
  void _cdecl LAPACK_CSPTRI (char const* uplo, int const* n, fcomplex_t const* ap, 
		      int const* ipiv, fcomplex_t* work, int* info);
  void _cdecl LAPACK_ZSPTRI (char const* uplo, int const* n, dcomplex_t const* ap, 
		      int const* ipiv, dcomplex_t* work, int* info);

  void _cdecl LAPACK_CHPTRS (char const* uplo, int const* n, int const* nrhs,
                      fcomplex_t const* ap, int const* ipiv, 
                      fcomplex_t* b, int const* ldb, int* info);
  void _cdecl LAPACK_ZHPTRS (char const* uplo, int const* n, int const* nrhs,
                      dcomplex_t const* ap, int const* ipiv, 
                      dcomplex_t* b, int const* ldb, int* info);

  /* banded */

  void _cdecl LAPACK_DGBTRF (int const* n, int const* m, int const* kl, int const* ku,
                      double* ab, int const* ldab, int* ipiv, int* info);

  void _cdecl LAPACK_DGBTRS (char const* trans, int const* n, int const* kl, int const* ku, int const* nrhs, 
                      double const* ab, int const* ldab, int const* ipiv, 
                      double* b, int const* ldb, int* info);


  /**********************************************************************/
  /*                         eigenproblems                              */
  /**********************************************************************/

  void _cdecl LAPACK_SGEES (const char* jobvs, const char* sort, logical_t* select, const int* n,
                     float* a, const int * lda, const int* sdim, float* wr, float* wi,
                     float* vs, const int * ldvs, float* work, const int * lwork,
                     bool* bwork, int* info);

  void _cdecl LAPACK_DGEES (const char* jobvs, const char* sort, logical_t* select, const int* n,
                     double* a, const int * lda, const int* sdim, double* wr, double* wi,
                     double* vs, const int * ldvs, double* work, const int * lwork,
                     bool* bwork, int* info);

  void _cdecl LAPACK_CGEES( const char* jobvs, const char* sort, logical_t* select, const int *n,
                     fcomplex_t* a, const int * lda, int * sdim, fcomplex_t* w, fcomplex_t* vs,
                     const int * ldvs, fcomplex_t* work, const int * lwork, float* rwork,
                     bool* bwork, int* info );

  void _cdecl LAPACK_ZGEES( const char* jobvs, const char* sort, const logical_t* select, const int *n,
                     dcomplex_t* a, const int * lda, int * sdim, dcomplex_t* w, dcomplex_t* vs,
                     const int * ldvs, dcomplex_t* work, const int * lwork, double* rwork,
                     bool* bwork, int* info );


  void _cdecl LAPACK_SGEEV( const char* jobvl, const char* jobvr, const int* n, float* a,
                    const int* lda, float* wr, float* wi, float* vl, const int* ldvl,
                    float* vr, const int* ldvr, float* work, const int* lwork, int* info );

  void _cdecl LAPACK_DGEEV( const char* jobvl, const char* jobvr, const int* n, double* a,
                    const int* lda, double* wr, double* wi, double* vl, const int* ldvl,
                    double* vr, const int* ldvr, double* work, const int* lwork, int* info );

  void _cdecl LAPACK_CGEEV( const char* jobvl, const char* jobvr, const int* n, fcomplex_t* a,
                    const int* lda, fcomplex_t* w, fcomplex_t* vl, const int* ldvl,
                    fcomplex_t* vr, const int* ldvr, fcomplex_t* work, const int* lwork,
                    float* rwork, int* info );

  void _cdecl LAPACK_ZGEEV( const char* jobvl, const char* jobvr, const int* n, dcomplex_t* a,
                    const int* lda, dcomplex_t* w, dcomplex_t* vl, const int* ldvl,
                    dcomplex_t* vr, const int* ldvr, dcomplex_t* work, const int* lwork,
                    double* rwork, int* info );


  void _cdecl LAPACK_SSYEV( const char* jobz, const char* uplo, const int *n,
                     float* a, const int * lda, float* w,
                     float* work, const int * lwork, int* info );

  void _cdecl LAPACK_DSYEV( const char* jobz, const char* uplo, const int *n,
                     double* a, const int * lda, double* w,
                     double* work, const int * lwork, int* info );

  void _cdecl LAPACK_CHEEV( const char* jobz, const char* uplo, const int *n,
                     fcomplex_t* a, const int * lda, float* w,
                     fcomplex_t* work, const int * lwork, float* rwork,
                     int* info );

  void _cdecl LAPACK_ZHEEV( const char* jobz, const char* uplo, const int *n,
                     dcomplex_t* a, const int * lda, double* w,
                     dcomplex_t* work, const int * lwork, double* rwork,
                     int* info );


  /* divide and conqer drivers for eigenvalue problems */
  void _cdecl LAPACK_SSYEVD( const char* jobz, const char* uplo, const int* n,
                      float* a, const int* lda, float* w,
                      float* work, const int* lwork,
                      int* iwork, const int* liwork, int* info);

  void _cdecl LAPACK_DSYEVD( const char* jobz, const char* uplo, const int* n,
                      double* a, const int* lda, double* w,
                      double* work, const int* lwork,
                      int* iwork, const int* liwork, int* info);

  void _cdecl LAPACK_CHEEVD( const char* jobz, const char* uplo, const int* n,
                      fcomplex_t* a, const int* lda, float* w,
                      fcomplex_t* work, const int* lwork, float* rwork, const int* lrwork,
                      int* iwork, const int* liwork, int* info);

  void _cdecl LAPACK_ZHEEVD( const char* jobz, const char* uplo, const int* n,
                      dcomplex_t* a, const int* lda, double* w,
                      dcomplex_t* work, const int* lwork, double* rwork, const int* lrwork,
                      int* iwork, const int* liwork, int* info);

  /* selective eignvector computation */
  void _cdecl LAPACK_SSYEVX( const char* jobz, const char* range, const char* uplo, const int* n,
                      float* a, const int* lda, const float* vl, const float* vu, const int* il, const int* iu,
                      const float* abstol, int* m, float* w, float* z, const int* ldz,
                      float* work, const int* lwork,
                      int* iwork, int* ifail, int* info);

  void _cdecl LAPACK_DSYEVX( const char* jobz, const char* range, const char* uplo, const int* n,
                      double* a, const int* lda, const double* vl, const double* vu, const int* il, const int* iu,
                      const double* abstol, int* m, double* w, double* z, const int* ldz,
                      double* work, const int* lwork,
                      int* iwork, int* ifail, int* info);

  void _cdecl LAPACK_CHEEVX( const char* jobz, const char* range, const char* uplo, const int* n,
                      fcomplex_t* a, const int* lda, const float* vl, const float* vu, const int* il, const int* iu,
                      const float* abstol, int* m, float* w, fcomplex_t* z, const int* ldz,
                      fcomplex_t* work, const int* lwork, float* rwork,
                      int* iwork, int* ifail, int* info);

  void _cdecl LAPACK_ZHEEVX( const char* jobz, const char* range, const char* uplo, const int* n,
                      dcomplex_t* a, const int* lda, const double* vl, const double* vu, const int* il, const int* iu,
                      const double* abstol, int* m, double* w, dcomplex_t* z, const int* ldz,
                      dcomplex_t* work, const int* lwork, double* rwork,
                      int* iwork, int* ifail, int* info);


  void _cdecl LAPACK_CTREVC( const char* side, const char* howmny, const logical_t* select, const int *n,
                     fcomplex_t* t, const int * ldt, fcomplex_t* vl, const int* ldvl,
		     fcomplex_t* vr, const int * ldvr, const int * nm, int* m, fcomplex_t* work,
                     float* rwork, int* info );

  void _cdecl LAPACK_ZTREVC( const char* side, const char* howmny, const logical_t* select, const int *n,
                     dcomplex_t* t, const int * ldt, dcomplex_t* vl, const int* ldvl,
		     dcomplex_t* vr, const int * ldvr, const int * nm, int* m, dcomplex_t* work,
                     double* rwork, int* info );

  void _cdecl LAPACK_STREVC( const char* side, const char* howmny, const logical_t* select, const int *n,
                     float* t, const int * ldt, float* vl, const int* ldvl,
		     float* vr, const int * ldvr, const int * nm, int* m, float* work,
                     int* info );

  void _cdecl LAPACK_DTREVC( const char* side, const char* howmny, const logical_t* select, const int *n,
                     double* t, const int * ldt, double* vl, const int* ldvl,
		     double* vr, const int * ldvr, const int * nm, int* m, double* work,
                     int* info );


  void _cdecl LAPACK_STREXC( const char* compq, const int *n,
                     float* t, const int * ldt, float* q, const int* ldq,
		     int* ifst, const int * ilst, float* work, int* info );

  void _cdecl LAPACK_DTREXC( const char* compq, const int *n,
                     double* t, const int * ldt, double* q, const int* ldq,
		     int* ifst, const int * ilst, double* work, int* info );

  void _cdecl LAPACK_CTREXC( const char* compq, const int *n,
                     fcomplex_t* t, const int * ldt, fcomplex_t* q, const int* ldq,
		     int* ifst, const int * ilst, int* info );

  void _cdecl LAPACK_ZTREXC( const char* compq, const int *n,
                     dcomplex_t* t, const int * ldt, dcomplex_t* q, const int* ldq,
		     int* ifst, const int * ilst, int* info );


  /* Hessenberg matrices */

  void _cdecl LAPACK_SHSEQR( const char* JOB, const char* COMPZ, const int* N, const int* ILO, const int* IHI, float* H, 
                      const int* LDH, float* WR, float* WI, float* Z, int const* LDZ,
                      float* WORK, const int* LWORK, int* INFO ) ;

  void _cdecl LAPACK_CHSEQR( const char* JOB, const char* COMPZ, const int* N, const int* ILO, const int* IHI, fcomplex_t* H, 
                      const int* LDH, fcomplex_t* W, fcomplex_t* Z, int const* LDZ,
                      fcomplex_t* WORK, const int* LWORK, int* INFO ) ;

  void _cdecl LAPACK_DHSEQR( const char* JOB, const char* COMPZ, const int* N, const int* ILO, const int* IHI, double* H, 
                      const int* LDH, double* WR, double* WI, double* Z, int const* LDZ,
                      double* WORK, const int* LWORK, int* INFO ) ;

  void _cdecl LAPACK_ZHSEQR( const char* JOB, const char* COMPZ, const int* N, const int* ILO, const int* IHI, dcomplex_t* H, 
                      const int* LDH, dcomplex_t* W, dcomplex_t* Z, int const* LDZ,
                      dcomplex_t* WORK, const int* LWORK, int* INFO ) ;

  /* Hermitian tridiagonal matrices */
  
  void _cdecl LAPACK_SSTEQR( char const* compz, int const* n, float* d, float* E, float* z, int const* ldz, float* work, int* info ) ;
  void _cdecl LAPACK_DSTEQR( char const* compz, int const* n, double* d, double* E, double* z, int const* ldz, double* work, int* info ) ;

  /* Hermitian banded matrices */
  
  void _cdecl LAPACK_SSBEV( char const* jobz, char const* uplo, int const* n,
                     int const* kd, float* ab, int const* ldab, float* w,
                     float* z, int const* ldz, float* work, int* info );

  void _cdecl LAPACK_DSBEV( char const* jobz, char const* uplo, int const* n,
                     int const* kd, double* ab, int const* ldab, double* w,
                     double* z, int const* ldz, double* work, int* info );

  void _cdecl LAPACK_CHBEV( char const* jobz, char const* uplo, int const* n,
                     int const* kd, fcomplex_t* ab, int const* ldab, float* w,
                     fcomplex_t* z, int const* ldz, fcomplex_t* work,
                     float* rwork, int* info );

  void _cdecl LAPACK_ZHBEV( char const* jobz, char const* uplo, int const* n,
                     int const* kd, dcomplex_t* ab, int const* ldab, double* w,
                     dcomplex_t* z, int const* ldz, dcomplex_t* work,
                     double* rwork, int* info );


  void _cdecl LAPACK_SSBEVX( char const* jobz, char const* range, char const* uplo, int const* n,
                      int const* kd, float* ab, int const* ldab, float* q, int const* ldq,
                      const float* vl, const float* vu, const int* il, const int* iu,
                      const float* abstol, int* m,
                      float* w, float* z, int const* ldz, float* work,
                      int* iwork, int* ifail, int* info );

  void _cdecl LAPACK_DSBEVX( char const* jobz, char const* range, char const* uplo, int const* n,
                      int const* kd, double* ab, int const* ldab, double* q, int const* ldq,
                      const double* vl, const double* vu, const int* il, const int* iu,
                      const double* abstol, int* m,
                      double* w, double* z, int const* ldz, double* work,
                      int* iwork, int* ifail, int* info );

  void _cdecl LAPACK_CHBEVX( char const* jobz, char const* range, char const* uplo, int const* n,
                      int const* kd, fcomplex_t* ab, int const* ldab, fcomplex_t* q, int const* ldq,
                      const float* vl, const float* vu, const int* il, const int* iu,
                      const float* abstol, int* m,
                      float* w, fcomplex_t* z, int const* ldz, fcomplex_t* work, float* rwork,
                      int* iwork, int* ifail, int* info );

  void _cdecl LAPACK_ZHBEVX( char const* jobz, char const* range, char const* uplo, int const* n,
                      int const* kd, dcomplex_t* ab, int const* ldab, dcomplex_t* q, int const* ldq,
                      const double* vl, const double* vu, const int* il, const int* iu,
                      const double* abstol, int* m,
                      double* w, dcomplex_t* z, int const* ldz, dcomplex_t* work, double* rwork,
                      int* iwork, int* ifail, int* info );


  /*********************************************************************/
  /*       Auxiliary routines for eigenvalue problems                  */
  /*********************************************************************/

  void _cdecl LAPACK_SSYTRD( char const* uplo, int const* n, float* a, int const* lda, float* d,
                      float* e, float* tau, float* work, int const* lwork, int* INFO ) ;

  void _cdecl LAPACK_DSYTRD( char const* uplo, int const* n, double* a, int const* lda, double* d,
                      double* e, double* tau, double* work, int const* lwork, int* INFO ) ;


  /**********************************************************************/
  /*               generalized eigenvalue / eigenvector                 */
  /**********************************************************************/

   void _cdecl LAPACK_SSYGV(int const* itype, char const* jobz, char const* uplo, int const* n,
                     float* a, int const* lda, float* b, int const* ldb,
                     float* w, float* work, int const* lwork, int* info);

   void _cdecl LAPACK_DSYGV(int const* itype, char const* jobz, char const* uplo, int const* n,
                     double* a, int const* lda, double* b, int const* ldb,
                     double* w, double* work, int const* lwork, int* info);

   void _cdecl LAPACK_CHEGV(int const* itype, char const* jobz, char const* uplo, int const* n,
                     fcomplex_t* a, int const* lda, fcomplex_t* b, int const* ldb,
                     float* w, fcomplex_t* work, int const* lwork, float* rwork, int* info);

   void _cdecl LAPACK_ZHEGV(int const *itype, char const* jobz, char const *uplo, int const * n,
                     dcomplex_t *a, int const *lda, dcomplex_t *b, int const *ldb,
                     double *w, dcomplex_t *work, int const *lwork, double* rwork, int* info);


  /*********************************************************************/
  /*                             SVD                                   */
  /*********************************************************************/

  void _cdecl LAPACK_SGESVD (char const* jobu, char const* jobvt, 
                      int const* m, int const* n, float* a, int const* lda, 
                      float* s, float* u, int const* ldu, 
                      float* vt, int const* ldvt,
                      float* work, int const* lwork, int* info); 
  void _cdecl LAPACK_DGESVD (char const* jobu, char const* jobvt, 
                      int const* m, int const* n, double* a, int const* lda, 
                      double* s, double* u, int const* ldu, 
                      double* vt, int const* ldvt,
                      double* work, int const* lwork, int* info); 
  void _cdecl LAPACK_CGESVD (char const* jobu, char const* jobvt, 
                      int const* m, int const* n, 
                      fcomplex_t* a, int const* lda, 
                      float* s, fcomplex_t* u, int const* ldu, 
                      fcomplex_t* vt, int const* ldvt,
                      fcomplex_t* work, int const* lwork, 
                      float* rwork, int* info); 
  void _cdecl LAPACK_ZGESVD (char const* jobu, char const* jobvt, 
                      int const* m, int const* n, 
                      dcomplex_t* a, int const* lda, 
                      double* s, dcomplex_t* u, int const* ldu, 
                      dcomplex_t* vt, int const* ldvt,
                      dcomplex_t* work, int const* lwork, 
                      double* rwork, int* info); 

  void _cdecl LAPACK_SGESDD (char const* jobz, int const* m, int const* n, 
                      float* a, int const* lda, 
                      float* s, float* u, int const* ldu, 
                      float* vt, int const* ldvt,
                      float* work, int const* lwork, int* iwork, int* info); 
  void _cdecl LAPACK_DGESDD (char const* jobz, int const* m, int const* n, 
                      double* a, int const* lda, 
                      double* s, double* u, int const* ldu, 
                      double* vt, int const* ldvt,
                      double* work, int const* lwork, int* iwork, int* info); 
  void _cdecl LAPACK_CGESDD (char const* jobz, int const* m, int const* n, 
                      fcomplex_t* a, int const* lda, 
                      float* s, fcomplex_t* u, int const* ldu, 
                      fcomplex_t* vt, int const* ldvt,
                      fcomplex_t* work, int const* lwork, 
                      float* rwork, int* iwork, int* info); 
  void _cdecl LAPACK_ZGESDD (char const* jobz, int const* m, int const* n, 
                      dcomplex_t* a, int const* lda, 
                      double* s, dcomplex_t* u, int const* ldu, 
                      dcomplex_t* vt, int const* ldvt,
                      dcomplex_t* work, int const* lwork, 
                      double* rwork, int* iwork, int* info); 


  /*********************************************************************/
  /*                    QR factorization                               */
  /*********************************************************************/

  void _cdecl LAPACK_SGEQRF( const int* m, const int* n, float* a, const int* lda,
                      float* tau, float* work, const int* lwork, int* info );
  void _cdecl LAPACK_DGEQRF( const int* m, const int* n, double* a, const int* lda,
                      double* tau, double* work, const int* lwork, int* info );
  void _cdecl LAPACK_CGEQRF( const int* m, const int* n, fcomplex_t* a, const int* lda,
                      fcomplex_t* tau, fcomplex_t* work, const int* lwork, int* info );
  void _cdecl LAPACK_ZGEQRF( const int* m, const int* n, dcomplex_t* a, const int* lda,
                      dcomplex_t* tau, dcomplex_t* work, const int* lwork, int* info );



  void _cdecl LAPACK_SORMQR( const char* side, const char* trans, const int* m,
                      const int* n, const int* k, const float* a,
                      const int* lda, const float* tau,
                      float* c, const int* ldc, float* work,
                      const int* lwork, int* info );
  void _cdecl LAPACK_DORMQR( const char* side, const char* trans, const int* m,
                      const int* n, const int* k, const double* a,
                      const int* lda, const double* tau,
                      double* c, const int* ldc, double* work,
                      const int* lwork, int* info );
  void _cdecl LAPACK_CUNMQR( const char* side, const char* trans, const int* m,
                      const int* n, const int* k, const fcomplex_t* a,
                      const int* lda, const fcomplex_t* tau,
                      fcomplex_t* c, const int* ldc, fcomplex_t* work,
                      const int* lwork, int* info );
  void _cdecl LAPACK_ZUNMQR( const char* side, const char* trans, const int* m,
                      const int* n, const int* k, const dcomplex_t* a,
                      const int* lda, const dcomplex_t* tau,
                      dcomplex_t* c, const int* ldc, dcomplex_t* work,
                      const int* lwork, int* info );

  void _cdecl LAPACK_SORGQR( const int* m, const int* n, const int* k,
                      float* a, const int* lda, float* tau,
                      float* work, const int* lwork, const int* info);
  void _cdecl LAPACK_DORGQR( const int* m, const int* n, const int* k,
                      double* a, const int* lda, double* tau,
                      double* work, const int* lwork, const int* info);
  void _cdecl LAPACK_CUNGQR( const int* m, const int* n, const int* k,
                      fcomplex_t* a, const int* lda, fcomplex_t* tau,
                      fcomplex_t* work, const int* lwork, const int* info);
  void _cdecl LAPACK_ZUNGQR( const int* m, const int* n, const int* k,
                      dcomplex_t* a, const int* lda, dcomplex_t* tau,
                      dcomplex_t* work, const int* lwork, const int* info);


  /********************************************************************/
  /*                          Least Squares                           */
  /********************************************************************/

  void _cdecl LAPACK_SGELS(const char* trans, const int* m, const int* n, 
					const int *nrhs, float* a, const int* lda,
					float* b, const int* ldb, float* work,
					const int* lwork, int* info);
  void _cdecl LAPACK_DGELS(const char* trans, const int* m, const int* n, 
					const int *nrhs, double* a, const int* lda,
					double* b, const int* ldb, double* work,
					const int* lwork, int* info);
  void _cdecl LAPACK_CGELS(const char* trans, const int* m, const int* n, 
					const int *nrhs, fcomplex_t* a, const int* lda,
					fcomplex_t* b, const int* ldb, fcomplex_t* work,
					const int* lwork, int* info);
  void _cdecl LAPACK_ZGELS(const char* trans, const int* m, const int* n, 
					const int *nrhs, dcomplex_t* a, const int* lda,
					dcomplex_t* b, const int* ldb, dcomplex_t* work,
					const int* lwork, int* info);


  void _cdecl LAPACK_SGELSS(const int *m, const int *n, const int *nrhs,
					 float *a, const int *lda, float *b, const int *ldb,
					 float *s, const float *rcond, int *rank, float *work,
					 const int *lwork, int *info);
  void _cdecl LAPACK_DGELSS(const int *m, const int *n, const int *nrhs,
					 double *a, const int *lda, double *b, const int *ldb,
					 double *s, const double *rcond, int *rank, double *work,
					 const int *lwork, int *info);
  void _cdecl LAPACK_CGELSS(const int *m, const int *n, const int *nrhs,
					 fcomplex_t *a, const int *lda, fcomplex_t *b, const int *ldb,
					 float *s, const float *rcond, int *rank, fcomplex_t *work,
					 const int *lwork, float *rwork, int *info);
  void _cdecl LAPACK_ZGELSS(const int *m, const int *n, const int *nrhs,
					 dcomplex_t *a, const int *lda, dcomplex_t *b, const int *ldb,
					 double *s, const double *rcond, int *rank, dcomplex_t *work,
					 const int *lwork, double *rwork, int *info);


  void _cdecl LAPACK_SGELSD(const int *m, const int *n, const int *nrhs,
					 float *a, const int *lda, float *b, const int *ldb,
					 float *s, const float *rcond, int *rank, float *work,
					 const int *lwork, int *iwork, int *info);
  void _cdecl LAPACK_DGELSD(const int *m, const int *n, const int *nrhs,
					 double *a, const int *lda, double *b, const int *ldb,
					 double *s, const double *rcond, int *rank, double *work,
					 const int *lwork, int *iwork, int *info);
  void _cdecl LAPACK_CGELSD(const int *m, const int *n, const int *nrhs,
					 fcomplex_t *a, const int *lda, fcomplex_t *b, const int *ldb,
					 float *s, const float *rcond, int *rank, fcomplex_t *work,
					 const int *lwork, float *rwork, int *iwork, int *info);
  void _cdecl LAPACK_ZGELSD(const int *m, const int *n, const int *nrhs,
					 dcomplex_t *a, const int *lda, dcomplex_t *b, const int *ldb,
					 double *s, const double *rcond, int *rank, dcomplex_t *work,
					 const int *lwork, double *rwork, int *iwork, int *info);



  /********************************************************************/
  /*                          auxiliary                               */
  /********************************************************************/

  int LAPACK_ILAENV (int const* ispec, const char* name, const char* opt,
                     int const* n1, int const* n2, int const* n3, 
                     int const* n4, int, int); 

}

#endif 
