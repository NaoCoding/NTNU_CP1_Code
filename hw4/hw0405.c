#include <stdio.h>
#include <stdint.h>

static int32_t your_hand[20][20], left = 14,meld_count[35] = {0},par_count = 0,hand_index = 0,hand_meld_index = 0;
static int32_t pair[2] = {0},winning_tile,player_wind,prevailing_wind;
static int32_t closed_opened_record[20];
static int32_t input_meld,open_close_detection,is_it_yakuman=0,is_it_doorclosed = 1;
static int32_t triplet_closed_and_open[2] = {0},straight_ = 0,kans=0;
int32_t triplet_straight_checker(int32_t arr[20]);
int32_t thirteen_orphan(){

    int32_t twice_counter = 0;
    for(int32_t i=0;i<35;i++){
        if(meld_count[i]){
            if(!(i==1||i==9||i==10||i==18||i==19||i>=27))return 0;
        }
        else{
            if(i==1||i==9||i==10||i==18||i==19||i>=27)return 0;
        }
    }
    return 1;

}

int32_t Four_concealed(){

    if(triplet_closed_and_open[1])return 0;
    if(triplet_closed_and_open[0]<4)return 0;
    if(triplet_closed_and_open[0]==4){
        return 1;
    }
    return 0;

}

int32_t Big_three_dragons(){

    if(meld_count[32]>=3&&meld_count[33]>=3&&meld_count[34]>=3)return 1;
    return 0;

}

int32_t fourwinds(){

    int32_t record[2] = {1,1};
    for(int32_t i=28;i<32;i++){
        if(meld_count[i]>=3)continue;
        if(meld_count[i]<3)record[0] = 0;
        if(meld_count[i]<2)record[1] = 0;
    }
    return record[0] + record[1];


}
int32_t all_honor(){

    for(int32_t i=1;i<=27;i++){
        if(meld_count[i])return 0;
    }
    return 1;

}
int32_t all_terminal(){
    int32_t record = 1;
    for(int32_t i=2;i<=8;i++)if(meld_count[i])return 0;
        for(int32_t i=11;i<=17;i++)if(meld_count[i])return 0;
            for(int32_t i=20;i<=26;i++)if(meld_count[i])return 0;
                for(int32_t i=28;i<=34;i++)if(meld_count[i])record = 0;
    return 1 + record;
}
int32_t all_green(){

    for(int32_t i=1;i<=34;i++){
        if(meld_count[i]){
            if(i!=11&&i!=12&&i!=13&&i!=15&&i!=17&&i!=33)return 0;
        }
    }
    return 1;

}
int32_t nine_gate(){

    int32_t record = 2;
    if(!is_it_doorclosed)return 0;
    for(int32_t i=1;i<19;i++)if(meld_count[i])return 0;
        for(int32_t i=28;i<35;i++)if(meld_count[i])return 0;
    if(meld_count[19]<3)return 0;
    if(meld_count[19]==4&&winning_tile==19){
        record = 1;
    }
    if(meld_count[19]==4&&winning_tile!=19){
        record = 0;
    }
    for(int32_t i=20;i<=26;i++){
        //printf("%d ",meld_count[i]);
        if(meld_count[i]>2)return 0;
        if(meld_count[i]==2&&winning_tile==i){
            if(record==2)record=1;
            else return 0;
        }
        if(meld_count[i]==2&&winning_tile!=i){
            if(record==1)return 0;
            record = 0;
        }
        if(meld_count[i]<1)return 0;
    }
    if(meld_count[27]<3)return 0;
    if(meld_count[27]==4&&winning_tile==27){
        if(record==2)record = 1;
        else return 0;
    }
    if(meld_count[27]==4&&winning_tile!=27){
        if(record==2)record = 0;
        else return 0;
    }
    if(record==2)return 0;
    if(record==1) return 2;
    return 1;


}

int32_t yakuman_counter(){

    int32_t yakuman_ = 0;
    if(fourwinds()==2){
        printf("    Big four winds (2 Yakuman)\n");
            yakuman_ += 2;

    }
    if(Four_concealed()&&meld_count[winning_tile]==2){
            printf("    Four concealed triplets single wait (2 Yakuman)\n");
            yakuman_ += 2;
        }
    if(nine_gate()==2){
        printf("    Nine gates nine wait (2 Yakuman)\n");
            yakuman_ += 2;
    }
    if(thirteen_orphan()&&meld_count[winning_tile]==2){
            printf("    Thirteen orphans 13 wait (2 Yakuman)\n");
            yakuman_ += 2;}
    if(all_green()){
        printf("    All green (1 Yakuman)\n");
        yakuman_ += 1;
    }
    if(all_honor()){
        printf("    All honors (1 Yakuman)\n");
        yakuman_ += 1;
    }
    if(all_terminal()==2){
        printf("    All terminals (1 Yakuman)\n");
        yakuman_ += 1;
    }
    if(Big_three_dragons()){
        printf("    Big three dragons (1 Yakuman)\n");
        yakuman_ += 1;
    }
    if(Four_concealed()&&meld_count[winning_tile]==3){
        printf("    Four concealed triplets (1 Yakuman)\n");
        yakuman_ += 1;

    }
    if(kans==4){
        printf("    Four kans (1 Yakuman)\n");
        yakuman_ += 1;
    }
    if(fourwinds()==1){
        printf("    Little four winds (1 Yakuman)\n");
            yakuman_ += 1;

    }
    if(nine_gate()==1){
        printf("    Nine gates (1 Yakuman)\n");
            yakuman_ += 1;
    }
    if(thirteen_orphan()&&meld_count[winning_tile]!=2){
            printf("    Thirteen orphans (1 Yakuman)\n");
            yakuman_+= 1;
    }









    if(yakuman_){
        printf("Total: %d Yakuman\n",yakuman_);
        return 1;
    }
    return 0;
}

int32_t seven_pair(){
    int32_t counter = 0;
    for(int32_t i=1;i<=34;i++){
        //printf("%d %d\n",i,meld_count[i]);
        if(meld_count[i]==2)counter += 1;
        else if(meld_count[i])return 0;
    }
    //printf("%d",counter);
    return counter == 7 ? 1:0;
}

int32_t identical_sequences(){
    int32_t sequences = 0;
    for(int32_t i=0;i<4;i++){
        for(int32_t j=i+1;j<4;j++){
            if(triplet_straight_checker(your_hand[i])==1){
                if(triplet_straight_checker(your_hand[j])==1){
                    int32_t same = 1;
                    for(int32_t k=0;k<20;k++){
                        if(your_hand[i][k]!=your_hand[j][k]){
                            same = 0;
                            break;
                        }
                    }
                    if(same==1)sequences += 1;
                }
            }
        }
    }
    if(straight_!=4)sequences = sequences >= 2 ? 1:sequences;

    return sequences;
}

int32_t Three_colour_straights(){

    if(straight_<3)return 0;
    for(int32_t i=0;i<4;i++){
        for(int32_t j=0;j<4;j++){
            for(int32_t k=0;k<4;k++){
                if(i!=j&&j!=k&&k!=i){
                    int32_t same = 0;
                    for(int32_t l=0;l<20;l++){
                        if(your_hand[i][l]%9==your_hand[j][l]%9&&your_hand[j][l]%9==your_hand[k][l]%9){
                            if(your_hand[i][l]!=your_hand[j][l]&&your_hand[i][l]%9==your_hand[k][l]%9){
                                if(your_hand[j][l]!=your_hand[k][l]){
                                    if(your_hand[k][l]!=your_hand[i][l]){
                                        same += 1;
                                    }
                                }
                            }
                        }
                    }
                    if(same==3)return 1;
                }
            }
        }
    }
    return 0;

}

int32_t StraightSSS(){

    if(straight_<3)return 0;
    int32_t same[3] = {0};
    for(int32_t i=1;i<=9;i++){
        for(int32_t j=0;j<=18;j+=9){
            if(meld_count[i+j]>0){
                same[j/9]+=1;
            }
        }
    }
    if(same[0]==9||same[1]==9||same[2]==9)return 1;
    return 0;

}

int32_t Three_colour_triplets(){

    if(triplet_closed_and_open[0]+triplet_closed_and_open[1]<3) return 0;
    for(int32_t i=1;i<=9;i++){
        if(meld_count[i] >= 3){
            if(meld_count[i+9] >= 3){
                if(meld_count[i+18] >=3){
                    return 1;
                }
            }
        }
    }
    return 0;

}

int32_t all_simple(){

    if(meld_count[1]>0)return 0;
    if(meld_count[9]>0)return 0;
    if(meld_count[10]>0)return 0;
    if(meld_count[18]>0)return 0;
    if(meld_count[19]>0)return 0;
    if(meld_count[27]>0)return 0;
    for(int32_t i=28;i<=34;i++)if(meld_count[i])return 0;
    return 1;

}

int32_t Terminal_or_honor_in_each_set(){

    int32_t all_terminal = 0;
    for(int32_t i=0;i<20;i++){
        int32_t having = 0;
        int32_t smthing = 0;
        for(int32_t j=0;j<20;j++){
            //printf("%d ",your_hand[i][j]);

            if(your_hand[i][j]>=28)having = 2;
            else if(your_hand[i][j]%9==1){
                if(having==0)having=1;
            }
            else if(your_hand[i][j]%9==0&&your_hand[i][j]!=0){
                if(having==0)having=1;
            }
            else if(your_hand[i][j]!=-1)smthing = 1;
        }
        //printf("\n");
        //printf("%d %d\n",having,smthing);
        if(having==2&&smthing) all_terminal = 1;
        if(having==1&&smthing&&all_terminal!=1) all_terminal = 2;
        else if(having==0&&smthing) return 0;
    }
    //printf("%d",all_terminal);
    return all_terminal;

}
int32_t all_terminal_and_honor(){

    for(int32_t i=1;i<28;i++){
        if(i%9!=0&&i%9!=1){
            if(meld_count[i])return 0;
        }
    }
    return 1;

}
int32_t Little_three_dragons(){

    int32_t three[2] = {0};
    for(int32_t i=32;i<=34;i++){
        if(meld_count[i]>=3)three[0] += 1;
        else if(meld_count[i]==2)three[1] += 1;
    }
    //printf("%d %d %d\n",meld_count[32],meld_count[33],meld_count[34]);
    return three[0] == 2 && three[1] == 1 ? 1:0;

}

int32_t flush_(){

    int32_t all_ = 2;
    for(int32_t i=28;i<=34;i++)if(meld_count[i]) all_ = 1;
    int32_t pll = 1;
    for(int32_t i=10;i<=27;i++)if(meld_count[i]) pll = 0;
    if(pll) return all_;
pll = 1;
    for(int32_t i=1;i<=18;i++)if(meld_count[i]) pll = 0;
    if(pll) return all_;
pll = 1;
    for(int32_t i=1;i<=9;i++)if(meld_count[i]) pll = 0;
    for(int32_t i=19;i<=27;i++)if(meld_count[i]) pll = 0;
    if(pll) return all_;
    return 0;


}

int32_t pin_ha(){
    int32_t c = 0;
    for(int32_t i=0;i<20;i++){
        for(int32_t j=0;j<20;j++){
            if(your_hand[i][j] == winning_tile){
                c = i;
                break;
            }
        }
    }
    if(straight_!=4)return 0;

    for(int32_t i=0;i<20;i++){
        if(your_hand[c][i]==-1)continue;
        if(your_hand[c][i]==winning_tile && your_hand[c][i-1] ==winning_tile-1 && your_hand[c][i+1]==winning_tile+1)return 0;
        if(your_hand[c][i]==winning_tile&&your_hand[c][i+1]==winning_tile+1 && your_hand[c][i+2]==winning_tile+2 && your_hand[c][i+2]%9==0)return 0;
        if(your_hand[c][i]==winning_tile&&your_hand[c][i-1]==winning_tile-1 && your_hand[c][i-2]==winning_tile-2 && your_hand[c][i-2]%9==1)return 0;

    }
    return 1;

}

int32_t yaku_counter(){

    int32_t yaku_ = 0;
    if(flush_()==2&&is_it_doorclosed==1){
        printf("    Flush (6 Han)\n");
        yaku_ += 6;
    }
    if(flush_()==2&&is_it_doorclosed==0){
        printf("    Flush (5 Han)\n");
        yaku_ += 5;
    }
    if(flush_()==1&&is_it_doorclosed==1){
        printf("    Half-flush (3 Han)\n");
        yaku_ += 3;
    }
    if(Terminal_or_honor_in_each_set()==2&&is_it_doorclosed==1){
        printf("    Terminal in each set (3 Han)\n");
        yaku_ += 3;
    }
    if(all_terminal_and_honor()){
        printf("    All terminals and honors (2 Han)\n");
        yaku_ += 2;
    }
    if(straight_==0&&triplet_closed_and_open[0]+triplet_closed_and_open[1]==4){
        printf("    All triplets (2 Han)\n");
        yaku_+= 2;
    }
    if(flush_()==1&&is_it_doorclosed==0){
        printf("    Half-flush (2 Han)\n");
        yaku_ += 2;
    }
    if(Little_three_dragons()){
        printf("    Little three dragons (2 Han)\n");
        yaku_ += 2;
    }
    if(seven_pair()&&straight_==0){
        printf("    Seven pairs (2 Han)\n");
        yaku_ += 2;
    }
    if(StraightSSS()&&is_it_doorclosed==1){
        printf("    Straight (2 Han)\n");
        yaku_ += 2;
    }
    if(Terminal_or_honor_in_each_set()==2&&is_it_doorclosed==0){
        printf("    Terminal in each set (2 Han)\n");
        yaku_ += 2;
    }
    if(Terminal_or_honor_in_each_set()==1&&is_it_doorclosed==1){
        printf("    Terminal or honor in each set (2 Han)\n");
        yaku_ += 2;
    }
    if(Three_colour_straights()&&is_it_doorclosed==1){
        printf("    Three colour straights (2 Han)\n");
        yaku_ += 2;
    }
    if(Three_colour_triplets()){
        printf("    Three colour triplets (2 Han)\n");
        yaku_ += 2;
    }
    if(triplet_closed_and_open[0]==3){
        printf("    Three concealed triplets (2 Han)\n");
        yaku_ += 2;
    }
    if(kans==3){
        printf("    Three kans (2 Han)\n");
        yaku_ += 2;
    }
    if(identical_sequences()==2&&is_it_doorclosed==1){
        printf("    Two set of identical sequences (2 Han)\n");
        yaku_ += 2;
    }

    if(all_simple()){
        printf("    All simples (1 Han)\n");
        yaku_ += 1;
    }
    if(meld_count[33]>=3){
        printf("    Honor: Green (1 Han)\n");
        yaku_ += 1;
    }



    if(meld_count[player_wind+28]>=3){
        printf("    Honor: Player 's wind (1 Han)\n");
        yaku_ += 1;

    }
    if(meld_count[prevailing_wind+28]>=3){
        yaku_ += 1;
        printf("    Honor: Prevailing wind (1 Han)\n");
    }
    if(meld_count[34]>=3){
        printf("    Honor: Red (1 Han)\n");
        yaku_ += 1;
    }
    if(meld_count[32]>=3){
        printf("    Honor: White (1 Han)\n");
        yaku_ += 1;
    }
    if(!triplet_closed_and_open[0]&&!triplet_closed_and_open[1]&&pin_ha()){
        printf("    No-points hand (1 Han)\n");
        yaku_ += 1;
    }
    if(identical_sequences()==1&&is_it_doorclosed==1){
        printf("    One set of identical sequences (1 Han)\n");
        yaku_ += 1;
    }
    if(StraightSSS()&&is_it_doorclosed==0){
        printf("    Straight (1 Han)\n");
        yaku_ += 1;
    }
    if(Terminal_or_honor_in_each_set()==1&&is_it_doorclosed==0){
        printf("    Terminal or honor in each set (1 Han)\n");
        yaku_ += 1;
    }
    if(Three_colour_straights()&&is_it_doorclosed==0){
        printf("    Three colour straights (1 Han)\n");
        yaku_ += 1;
    }
    if(!yaku_)printf("    No Yaku\n");
    printf("Total: %d Han",yaku_);
    return yaku_;
}

void error_case_output(){printf("The Score is... \n    Unreasonable case \nTotal: 0 Han\n");
}
void bub_sorting(int32_t arr[20]){
    for(int i=0;i<20;i++){
        for(int j=i+1;j<20;j++){
            if(arr[i]>arr[j]){
                int32_t temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
int32_t over_meld(int32_t target){return meld_count[target] > 4 ? 1:0;}
int32_t triplet_straight_checker(int32_t arr[20]){
    bub_sorting(arr);
    int32_t ans = -1;
    int32_t rad = 0;
    for(int i=0;i<19;i++){
        //printf("%d\n",arr[i]);
        if(rad) break;
        if(arr[i] > 34 || arr[i]<=0)continue;
        if(arr[i+1] > 34 || arr[i+1]<=0)continue;
        if(arr[i] == arr[i+1]){
            if(ans==-1) ans = 0;
            else if(ans==1) rad = 1;
        }
        else if(arr[i] + 1==arr[i+1]){
            if(ans==-1) ans = 1;
            else if(ans==0) rad = 1;
        }

    }
    //printf("%d %d",rad,ans);
    return rad == 1 ? 2:ans;
}

int main(){


    for(int32_t i=0;i<20;i++){
        for(int32_t j=0;j<20;j++)your_hand[i][j] = -1;
    }
    while(left>2){
        if(!par_count) printf("Please input meld: ");
        scanf("%d",&input_meld);
        if(input_meld<0||input_meld>34){
            error_case_output();
            return 0;
        }

        if(!input_meld){
            if(par_count!=14 && par_count!=3 && par_count!=4){
                error_case_output();
                return 0;
            }
            if(par_count!=14){
                printf("Is open group(1: YES 0: NO): ");
            scanf("%d",&open_close_detection);
            if(open_close_detection!=1 && open_close_detection !=0){
                error_case_output();
                return 0;
            }
            if(open_close_detection) is_it_doorclosed = 0;
            if(triplet_straight_checker(your_hand[hand_meld_index])==0){
                triplet_closed_and_open[open_close_detection] += 1 ;
                if(par_count==4) kans++;
            }
            else if(triplet_straight_checker(your_hand[hand_meld_index])==1){
                straight_ += 1;
            }
            else{
                error_case_output();
                return 0;
            }
            }

            closed_opened_record[hand_meld_index] = open_close_detection;
            left -= (par_count == 4)?3:par_count;
            par_count = 0;
            hand_index = 0;
            hand_meld_index += 1;

        }
        else{
            par_count += 1;
            meld_count[(int32_t)input_meld] += 1;
            if(over_meld(input_meld)||par_count > 14){
            error_case_output();
            return 0;
            }
            your_hand[hand_meld_index][hand_index] = input_meld;
            hand_index += 1;
        }
    }
    if(left<0){
        error_case_output();
        return 0;
    }
    else if(left == 2){
        printf("Please input pair:");
        for(int32_t i=0;i<2;i++){
            scanf("%d",&pair[i]);
            meld_count[pair[i]]+= 1;
            if(pair[i]<0||pair[i]>34){
            error_case_output();
            return 0;
            }
            if(over_meld(pair[i])){
            error_case_output();
            return 0;
        }your_hand[hand_meld_index][i] = pair[i];}
        if(pair[0]!=pair[1]){
            error_case_output();
            return 0;
        }


    }
    printf("Please input winning tile: ");
    scanf("%d",&winning_tile);
    if(winning_tile<0||winning_tile>34){
            error_case_output();
            return 0;
        }
    if(meld_count[winning_tile]<1){
        error_case_output();
            return 0;
    }

    printf("Player's wind(0:E 1:S 2:W 3:N): ");
    scanf("%d",&player_wind);
    if(player_wind<0 || player_wind>3){
            error_case_output();
            return 0;
        }
    printf("Prevailing wind(0:E 1:S 2:W 3:N): ");
    scanf("%d",&prevailing_wind);
    if(prevailing_wind<0||prevailing_wind>3){
        error_case_output();
            return 0;
    }

    printf("The Score is...\n");
    if(!yakuman_counter()){
        if(yaku_counter()>=13){
            printf(" (Kazoe-yakuman)\n");
        }
        else{
            printf("\n");
        }
    }




}


