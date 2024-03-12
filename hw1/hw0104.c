#include <stdio.h>
#include <stdint.h>

int32_t suit1,suit2,suit3,suit4,high1,high2,high3,high4;
int32_t hcp = 0,card;

int32_t valid(int32_t no){

    if(no<1||no>52) return 0;
    return 1;

}

int32_t balanced(){
int32_t ccc = 0,threes=0;
	if(suit1==3){threes ++;}
	else if(suit1==4) ccc += 1;
	if(suit2==3){threes ++;}
	else if(suit2==4) ccc += 1;
	if(suit3==3){threes ++;}
	else if(suit3==4) ccc += 1;
	if(suit4==3){threes ++;}
	else if(suit4==4) ccc += 1;
	
	
	if(ccc==1&&threes==3) return 1;
	return 0;

}

int32_t high_check(int suit){

	if(suit==1) return high1;
	if(suit==2) return high2;
	if(suit==3) return high3;
	if(suit==4) return high4;

}

int32_t suit_check(int32_t count){

	if(suit1==count) return 1;
	if(suit2==count) return 2;
	if(suit3 == count) return 3;
	if(suit4 == count) return 4;
	return 0;

}

int32_t suit_equal(){
	int32_t max_h=suit1,equal = 0;
	if(suit2>max_h)max_h = suit2;
	else if(suit2==max_h)equal=1;
	if(suit3>max_h){max_h=suit3;
	equal=0;}
	else if(suit3==max_h)equal = 1;
	if(suit4>max_h)return 0;
	else if(suit4==max_h) return 1;
	return equal;
}
int32_t hcp_counter(int32_t card){

	if(card%13 == 1) return 4;
	if(card%13 == 0) return 3;
	if(card%13 == 12) return 2;
	if(card%13 == 11) return 1;
	return 0;

}
void suit_counter(int32_t card){
	if(card<=13) suit1 += 1;
	else if(card<=26) suit2+=1;
	else if(card<40) suit3+=1;
	else suit4 += 1;
	//printf("%d %d %d %d\n",suit1,suit2,suit3,suit4);
}
int32_t suit_max(){
	int32_t max_h;
	max_h = suit1;
	max_h = max_h>suit2? max_h:suit2;
	max_h = max_h>suit3? max_h:suit3;
	max_h = max_h>suit4? max_h:suit4;
	return max_h;

}
void high_counter(int card){

	if(card%13 == 1||card%13==0||card%13==12){
	if(card<=13) high1 += 1;
	else if(card<=26) high2+=1;
	else if(card<40) high3+=1;
	else high4 += 1;}


}

int main(){


    
    printf("1st card: ");
    scanf("%d",&card);
    hcp += hcp_counter(card);
    suit_counter(card);
    high_counter(card);
    if(!valid(card)){
        printf("The card input out of range!\n");
        return 0;
    }
    printf("2nd card: ");
    scanf("%d",&card);
    suit_counter(card);
    high_counter(card);
    hcp += hcp_counter(card);
    if(!valid(card)){
        printf("The card input out of range!\n");
        return 0;
    }
    printf("3rd card: ");
    scanf("%d",&card);
    suit_counter(card);
    high_counter(card);
    hcp += hcp_counter(card);
    if(!valid(card)){
        printf("The card input out of range!\n");
        return 0;
    }
    printf("4th card: ");
    scanf("%d",&card);
    suit_counter(card);
    high_counter(card);
    if(!valid(card)){
        printf("The card input out of range!\n");
        return 0;
    }
    hcp += hcp_counter(card);
    printf("5th card: ");
    scanf("%d",&card);
    suit_counter(card);
    high_counter(card);
    hcp += hcp_counter(card);
    if(!valid(card)){
        printf("The card input out of range!\n");
        return 0;
    }
    printf("6th card: ");
    scanf("%d",&card);
    suit_counter(card);
    high_counter(card);
    hcp += hcp_counter(card);
    if(!valid(card)){
        printf("The card input out of range!\n");
        return 0;
    }
    printf("7th card: ");
    scanf("%d",&card);
    suit_counter(card);
    high_counter(card);
    hcp += hcp_counter(card);
    if(!valid(card)){
        printf("The card input out of range!\n");
        return 0;
    }
    printf("8th card: ");
    scanf("%d",&card);
    suit_counter(card);
    high_counter(card);
    hcp += hcp_counter(card);
    if(!valid(card)){
        printf("The card input out of range!\n");
        return 0;
    }
    printf("9th card: ");
    scanf("%d",&card);
    suit_counter(card);
    high_counter(card);
    hcp += hcp_counter(card);
    if(!valid(card)){
        printf("The card input out of range!\n");
        return 0;
    }
    printf("10th card: ");
    scanf("%d",&card);
    suit_counter(card);
    high_counter(card);
    hcp += hcp_counter(card);
    if(!valid(card)){
        printf("The card input out of range!\n");
        return 0;
    }
    printf("11th card: ");
    scanf("%d",&card);
    suit_counter(card);
    high_counter(card);
    hcp += hcp_counter(card);
    if(!valid(card)){
        printf("The card input out of range!\n");
        return 0;
    }
    printf("12th card: ");
    scanf("%d",&card);
    suit_counter(card);
    high_counter(card);
    hcp += hcp_counter(card);
    if(!valid(card)){
        printf("The card input out of range!\n");
        return 0;
    }
    printf("13th card: ");
    scanf("%d",&card);
    suit_counter(card);
    high_counter(card);
    hcp += hcp_counter(card);
    if(!valid(card)){
        printf("The card input out of range!\n");
        return 0;
    }
    
    
    
    
    //S H D C
    printf("---\n");
    printf("HCP: %d pts\n",hcp);
    printf("Suit: %d-%d-%d-%d\n",suit1,suit2,suit3,suit4);
    printf("The bidding choice : ");
    if(24>=hcp&&hcp>=22&&balanced()) printf("2NT\n");
    else if(hcp>=16)printf("1C\n");
    else if(hcp>=11&&(suit1>=5||suit2>=5)){
        if(suit1>=suit2)printf("1S\n");
        else printf("1H\n");
    }
    else if(hcp>=13&&balanced())printf("1NT\n");
    else if(11<=hcp&&hcp<=15&&suit3>=4) printf("1D\n");
    else if(11<=hcp&&hcp<=15&&suit4>=6) printf("2C\n");
    else if(11<=hcp&&hcp<=15&&suit4>=5&&suit3==0) printf("2D\n");
    else if(8<=hcp&&hcp<=10&&suit1==6)printf("2S\n");
    else if(8<=hcp&&hcp<=10&&suit2==6)printf("2H\n");
    else if(suit_max()==7&&8<=hcp&&hcp<=11){
    int32_t output_suit = suit_check(7);
    	if(output_suit==1)printf("3S\n");
    	else if(output_suit==2) printf("3H\n");
    	else if(output_suit==3) printf("3D\n");
    	else if(output_suit==4) printf("3C\n");
    }
    else if(suit_max()==7&&hcp<16&&high_check(suit_check(7))==3) printf("3NT\n");
    else printf("Pass\n");

    return 0;

}
