clc;
clear all;
f = @(x) 1./(1 + x.^2);   % function
a = 0; 
b = 12; 
n = 6;

h = (b - a) / n;          % step size
x = a:h:b;                % partition points
y = f(x);                 % function values

% Apply trapezoidal rule
I = h * ( 0.5*y(1) + sum(y(2:end-1)) + 0.5*y(end) );

fprintf('Approximate value of integral using trapezoidal rule (n=6) = %.4f\n', I);
