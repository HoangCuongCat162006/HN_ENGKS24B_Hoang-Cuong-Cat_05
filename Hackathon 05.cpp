#include<stdio.h>

int main(){
  
  int arr[100];
  int n=0;
  int choice,lement,position;


  
  while (1){
		printf("\nMENU:\n");
        printf("1. Nhap so phan tu va gia tri cho mang\n");
        printf("2. In ra gia tri cac phan tu trong mang\n");
        printf("3. Dem so luong cac so hoan hao trong mang\n");
        printf("4. Tim gia tri nho thu 2 trong mang\n");
        printf("5. Them mot phan tu vao vi tri dau tien\n");
        printf("6. Xoa phan tu tai vi tri cu the\n");
        printf("7. Sap xep mang theo thu tu giam dan\n");
        printf("8. Tim kiem phan tu trong mang (Binary search)\n");
        printf("9. Sap xep lai mang so le dung truoc, so chan dung sau\n");
        printf("10. Dao nguoc mang va hien thi\n");
        printf("0. Thoat\n");
        printf("Lua chon: ");
        scanf("%d", &choice);
        
        if (choice==0)
        break;
        
        switch (choice) {
            case 1:
                printf("Nhap so phan tu cua mang: ");
                scanf("%d", &n);
                printf("Nhap gia tri cac phan tu:\n");
                for (int i = 0; i < n; i++) {
                    printf("arr[%d] = ", i);
                    scanf("%d", &arr[i]);
            	}
            	break;
            case 2:
            	printf("Gia tri cac phan tu trong mang la ");
            	    printf("Mang hien tai:\n");
                for (int i = 0; i < n; i++) {
                    printf("arr[%d] = %d\n", i, arr[i]);
                }
                break;
             case 3: {
                int perfectCount = 0;
                for (int i = 0; i < n; i++) {
                    int sum = 0;
                    for (int j = 1; j <= arr[i] / 2; j++) {
                        if (arr[i] % j == 0) sum += j;
                    }
                    if (sum == arr[i]) perfectCount++;
                }
                printf("So luong so hoan hao: %d\n", perfectCount);
                break;
            }
            case 4: {
                int min = 1e9, secondMin = 1e9;
                for (int i = 0; i < n; i++) {
                    if (arr[i] < min) {
                        secondMin = min;
                        min = arr[i];
                    } else if (arr[i] < secondMin && arr[i] != min) {
                        secondMin = arr[i];
                    }
                }
                if (secondMin == 1e9)
                    printf("Khong co gia tri nho thu 2\n");
                else
                    printf("Gia tri nho thu 2: %d\n", secondMin);
                break;
            }
            case 5:
            	printf("Nhap gia tri can them vao dau tien trong mang : ");
            	scanf("%d",lement);
            	for (int i=n;i<0;i--){
            		arr[i]=arr[i-1];
				}
				arr[0]=lement;
            	n++;
            	break;
			case 6:
				printf("Nhap vi tri can xoa : ");
				scanf("%d",&position);
				if (position < 0 || position >= n) {
                    printf("Vi tri khong hop le!\n");
                } else {
                    for (int i = position; i < n - 1; i++) {
                        arr[i] = arr[i + 1];
                    }
                    n--;
                }
                break;
        	case 7:
        		for(int i=0;i<n-1;i++){
        			int maxindex = i;
        			for (int j=i+1;i<n;j++){
        				if (arr[j]>arr[maxindex]) maxindex=j ;
					}
					if (maxindex!= i ){
						int temp = arr[i];
						arr[i]=arr[maxindex];
						arr[maxindex=temp];
					}
				}
			case 8: {
                int search = 0;
				int found = 0;
                printf("Nhap phan tu can tim: ");
                scanf("%d", &search);
                for (int i = 0; i < n; i++) {
                    if (arr[i] == search) {
                        printf("Tim thay phan tu tai vi tri %d\n", i);
                        found = 1;
                        break;
                    }
                }
                if (!found) printf("Khong tim thay phan tu.\n");
                break;
            }
			default:
				printf("Lua chon khong hop le \n ");
				
  		}
    }

	return 0;
}
