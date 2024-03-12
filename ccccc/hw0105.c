#include <stdio.h>
#include <stdint.h>
int32_t rightcomma = 0, title_space = 0;


int main(){

	int32_t local_part_error=0, cap = 0,domain_error = 1,test=-1,sum_ofava=0,check_domain,total_domain=0;
	char domain_checker='!';
	int32_t test2=0;
	printf("Please enter the sender address      > ");
	scanf("%*[a-zA-Z0-9]@%n",&cap);
	int32_t after_cap = 0;
	int32_t after_do=-1;
	if(cap==0){
		 local_part_error = 1;
        scanf("%*[^\n\r]@%n",&after_cap);

	}

		scanf("csie.cool%c%n",&domain_checker,&check_domain);
		total_domain += check_domain;
	if((domain_checker=='\n')){
		 domain_error =0;
		 sum_ofava ++;

	}else if(domain_checker!='!')domain_error = 2;
	else{
		domain_checker = '!';
		scanf("ntnu.edu.tw%c%n",&domain_checker,&check_domain);
		total_domain += check_domain;
		if((domain_checker=='\n')){
			domain_error = 0;
			sum_ofava ++;
		}
		else if(domain_checker!='!')domain_error = 2;
		else{
			domain_checker = '!';
			scanf("gapps.ntnu.edu.tw%c%n",&domain_checker,&check_domain);
			total_domain += check_domain;
			if((domain_checker=='\n')){
				domain_error = 0;
			sum_ofava ++;
		}else if(domain_checker!='!')domain_error = 2;else{
			domain_checker = '!';
			scanf("csie.ntnu.edu.tw%c%n",&domain_checker,&check_domain);
			total_domain += check_domain;
			if((domain_checker=='\n')){
				domain_error=0;
				sum_ofava ++;
			}
			else if(domain_checker!='!')domain_error = 2;else{
					scanf("%c",&domain_checker);
					if(domain_checker!='\n'){

						scanf("%*[^\n\r]%n",&after_do);
						//printf("%d %d %d",domain_checker,after_do,test);
					}

			}
		}

		}
	}

	if(sum_ofava>1){
		domain_error = 1;
	}
	if(domain_error==2) scanf("%*[^\n\r]%n",&after_do);

    int32_t escape = 0;
	//if((test==-1&&domain_checker!='\n')||after_cap>0||cap==0&&after_cap==0) scanf("\n%n",&escape);


	int32_t A=-999,B=-999, no_title_error=0, no_category_error=0;
	int32_t out_range_error = 0, too_low_error = 0;
	int32_t title_size=0 , category = -1;
	int64_t temp2;
	char temp1='a';

	int32_t useless;

	printf("Please enter the email subject       > ");

	/*scanf("[%*[a-zA-Z]%n",&temp1);
	scanf("%d]",&A);
	scanf("[p%n",&temp2);
	scanf("%d]",&B);
	if(A!=0) rightcomma = 1;*/
	int32_t left_checker = 0;
	char left =  -1;
	if(domain_checker!='\n'&&after_do!=-1) scanf("\n");
	scanf("%c",&left);
	if(left=='['){
		scanf("hw%d][p%d]",&A,&B);
	if(A==-999||B==-999){
        scanf("general]%n",&category);
        if(category==-1) no_category_error = 1;
	}
	}
	else no_category_error = 1;

	//printf("%c",temp1);
	if(left!='\n'){
		scanf("%c",&left);}


	if(left!='\n'){
		scanf("%*[^\n\r]%n",&title_size);
	}
	else title_size = 0;
	//printf("%d %d",left,title_size );


	//printf("%ld %d\n",title_size,temp1);
	if(title_size<1) no_title_error = 1;
	if(left!=' ') title_size += 1;
	//printf("%d",title_size);

	int32_t ta = (A*B)%5;


	double score;
	printf("Please enter the email content score > ");
	if(title_size>0||left!='\n')scanf("\n");
	scanf("%lf",&score);
	if(score<0||score/1000000000>10000000000) out_range_error = 1;
	if(score<title_size*10000000000)too_low_error = 1;

	







	int32_t all_pass = 1;
	printf("================================================================================\n");

	//printf("%d %d",domain_error,local_part_error);
	if(domain_error==0&&local_part_error==0){
		printf("Sender Address Test : Passed\n");
		if(!no_category_error&&!no_title_error){
			printf("Email Subject Test : Passed\n");
			if(!out_range_error&&!too_low_error){
				printf("Email Content Test : Passed\n");
			}
			else{
				all_pass = 0;
				printf("Email Content Test : Failed, ");
				if(out_range_error)printf("out of range\n");
				else printf("too low\n");
			}
		}
		else{
			all_pass = 0;
			printf("Email Subject Test : Failed, ");
			if(no_category_error){
				printf("no category\n");
			}
			else printf("title is empty\n");
			printf("Email Content Test : -\n");
		}
	}
	else{
		all_pass = 0;
		printf("Sender Address Test : Failed, ");
		if(local_part_error==1) printf("local-part is invalid\n");
		else printf("domain is not authorized\n");
		printf("Email Subject Test : -\n");
		printf("Email Content Test : -\n");
	}
	printf("--------------------------------------------------------------------------------\n\n");
	if(!all_pass) printf("Rejected\n");
	else if(category==8)printf("Assigned to TA QB\n");
	else{
		printf("Assigned to ");
		if(ta==0) printf("Kaname Madoka\n");
		if(ta==1) printf("Akemi Homura\n");
		if(ta==2) printf("Miki Sayaka\n");
		if(ta==3) printf("Tomoe Mami\n");
		if(ta==4) printf("Sakura Kyoko\n");
	}
	return 0;
}
