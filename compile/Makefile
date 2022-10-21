SRCDIR = ../src
INCDIR = ../include
BINDIR = ../bin
OBJDIR = ../obj
CFLAGS = gcc -c -g -I${INCDIR}

all:	main.o generate_ID.o manage_customer.o manage_request.o reports.o requests.o 

main.o:
	${CFLAGS} ${SRCDIR}/main.c -o ${OBJDIR}/main.o
CRM_login.o:
	${CFLAGS} ${SRCDIR}/CRM_login.c -o ${OBJDIR}/CRM_login.o
customer_login.o:
	${CFLAGS} ${SRCDIR}/customer_login.c -o ${OBJDIR}/customer_login.o	
generate_ID.o:
	${CFLAGS} ${SRCDIR}/generate_ID.c -o ${OBJDIR}/generate_ID.o
manage_customer.o:	
	${CFLAGS} ${SRCDIR}/manage_customer.c -o ${OBJDIR}/manage_customer.o
manage_request.o:	
	${CFLAGS} ${SRCDIR}/manage_request.c -o ${OBJDIR}/manage_request.o	
reports.o:
	${CFLAGS} ${SRCDIR}/reports.c -o ${OBJDIR}/reports.o
requests.o:	
	${CFLAGS} ${SRCDIR}/requests.c -o ${OBJDIR}/requests.o	


finalexe: 
	gcc ${OBJDIR}/main.o ${OBJDIR}/generate_ID.o ${OBJDIR}/manage_customer.o ${OBJDIR}/manage_request.o ${OBJDIR}/reports.o ${OBJDIR}/requests.o -o ${BINDIR}/main.exe

clean:
	rm ${OBJDIR}/main.o ${OBJDIR}/generate_ID.o ${OBJDIR}/manage_customer.o ${OBJDIR}/manage_request.o ${OBJDIR}/reports.o ${OBJDIR}/requests.o 
