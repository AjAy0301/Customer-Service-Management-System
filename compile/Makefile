SRCDIR = ../src
INCDIR = ../include
BINDIR = ../bin
OBJDIR = ../obj
CFLAGS = gcc -c -g -I${INCDIR}

all:	main.o validate.o CRM_login.o customer_login.o customers.o requests.o reports.o requests_desc.o

main.o:
	${CFLAGS} ${SRCDIR}/main.c -o ${OBJDIR}/main.o
CRM_login.o:
	${CFLAGS} ${SRCDIR}/CRM_login.c -o ${OBJDIR}/CRM_login.o
customer_login.o:
	${CFLAGS} ${SRCDIR}/customer_login.c -o ${OBJDIR}/customer_login.o	
validate.o:
	${CFLAGS} ${SRCDIR}/validate.c -o ${OBJDIR}/validate.o
customers.o:	
	${CFLAGS} ${SRCDIR}/customers.c -o ${OBJDIR}/customers.o
requests.o:	
	${CFLAGS} ${SRCDIR}/requests.c -o ${OBJDIR}/requests.o	
reports.o:
	${CFLAGS} ${SRCDIR}/reports.c -o ${OBJDIR}/reports.o
requests_desc.o:	
	${CFLAGS} ${SRCDIR}/requests_desc.c -o ${OBJDIR}/requests_desc.o

finalexe: 
	gcc ${OBJDIR}/main.o ${OBJDIR}/CRM_login.o ${OBJDIR}/customer_login.o ${OBJDIR}/requests.o ${OBJDIR}/reports.o ${OBJDIR}/requests_desc.o ${OBJDIR}/validate.o -o ${BINDIR}/application.exe

clean:
	rm ${OBJDIR}/main.o ${OBJDIR}/CRM_login.o ${OBJDIR}/customer_login.o ${OBJDIR}/requests.o ${OBJDIR}/reports.o ${OBJDIR}/requests_desc.o ${OBJDIR}/validate.o
