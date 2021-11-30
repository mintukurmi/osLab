#include<stdio.h>
int main()
{
    int temp[10], flag1, flag2, flag3, i, j, k, pos, max, faults = 0;
    
    // setting the given values
    int frames_count=3;
    int pages_count=11;
    int frames[frames_count]; 
    
    // printing the given reference string
    printf("Given reference string: ");
    int pages[] = {3, 2, 1, 3, 4, 1, 6, 2, 4, 1, 6};
    for(i = 0; i < pages_count; ++i){
        printf("%d, ", pages[i]);
    }
    
    // setting all the pages of each frames as -1
    for(i = 0; i < frames_count; ++i){
        frames[i] = -1;
    }
    
    for(i = 0; i < pages_count; ++i){
        flag1 = flag2 = 0;
        
        for(j = 0; j < frames_count; ++j){
            if(frames[j] == pages[i]){
                   flag1 = flag2 = 1;
                   break;
               }
        }
        
        if(flag1 == 0){
            for(j = 0; j < frames_count; ++j){
                if(frames[j] == -1){
                    faults++;
                    frames[j] = pages[i];
                    flag2 = 1;
                    break;
                }
            }    
        }
        
        if(flag2 == 0){
            flag3 =0;
        
            for(j = 0; j < frames_count; ++j){
                    temp[j] = -1;
                    
                    for(k = i + 1; k < pages_count; ++k){
                    if(frames[j] == pages[k]){
                    temp[j] = k;
                    break;
                    }
                }
            }
            
            for(j = 0; j < frames_count; ++j){
                if(temp[j] == -1){
                    pos = j;
                    flag3 = 1;
                    break;
                }
            }
            
            if(flag3 ==0){
             max = temp[0];
             pos = 0;
            
             for(j = 1; j < frames_count; ++j){
                    if(temp[j] > max){
                        max = temp[j];
                        pos = j;
                    }
                }            
            }
        frames[pos] = pages[i];
        faults++;
        
        }
        
    }
    
    printf("\nTotal Page Faults = %d\n\n", faults);
    
    return 0;
}