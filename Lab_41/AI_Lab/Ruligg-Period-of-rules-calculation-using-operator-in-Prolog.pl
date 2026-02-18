% Ruligg Period of rules calculation
%https://www.youtube.com/watch?v=yuR7KsfA55A&list=PLEJXowNB4kPy3_qhGksOO8ch_Di7T8_9E&index=15
reigms(khalid,1900,1950).
reigms(mohammad,1951,1970).
reigms(labib,1971,1985).
reigms(yakub,1986,2010).

ruler(X,Y):-reigms(X,A,B),
            Y>=A,
            Y=<B.