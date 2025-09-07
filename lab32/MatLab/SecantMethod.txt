clc;
clear all;
fx=input('Enter the function ,F(x) = ','s');
f=eval(['@(x)',fx]) ;
a=input('Enter a=');
b=input('Enter b=');
x(1)=a;
x(2)=b;
s=1;
fprintf('N\t\t x(i-1)\t\t x(i)\t\t x(i+1)\t\t f(x)\t\t Error\n');
for k=3:103;
it(k)=abs(k-2);
x(k)=x(k-1)-(f(x(k-1))*(x(k-1)-x(k-2)))/(f(x(k-1))-f(x(k-2)));
c=f(x(k));
fprintf('%g %f %f %f %f %f\n\n',it(k),x(k-2),x(k-1),x(k),c,s);
s=((abs(x(k)-x(k-1)))/abs(x(k)))*100;
if s<=.001
break;
end
end
fprintf('\n\nThe root is =%f',x(k));