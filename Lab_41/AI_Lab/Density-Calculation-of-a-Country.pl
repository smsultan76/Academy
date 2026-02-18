% Calculation of Density of Population of a particular country
population(china,100).
population(india,90).
population(usa,80).
population(bangladesh,120).
area(china,10).
area(india,6).
area(usa,4).
area(bangladesh,10).
density(X,Y):-population(X,Pop),       %density(bangladesh,X).
              area(X,Ar),
              Y is Pop/Ar.
