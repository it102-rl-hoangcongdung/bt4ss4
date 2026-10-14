#include <stdio.h>

int main() {
    int total_orders;
    int completed_orders = 0;
    int cancelled_orders = 0;
    double total_revenue = 0.0;

    printf('=== HIGHLANDS COFFEE POS TRANSACTION ENGINE ===\n');
    printf('Nhap vao tong so don hàng trong ca: ');
    if (scanf('%d', &total_orders) != 1 || total_orders <= 0) {
        printf('So luong don hang khong hop le!\n');
        return 1;
    }

    for (int i = 0; i < total_orders; i++) {
        int order_status;
        double base_price;
        int size_choice;
        int topping_count;
        int is_gold_member;

        printf('\n--- Nhap thong tin don hang thu %d ---\n', i + 1);
        printf('Trang thai don (1: Thanh cong, 0: Huy/Loi nguyen lieu, -1: Su co khan cap dong ca): ');
        scanf('%d', &order_status);

        if (order_status == -1) {
            printf('[CANH BAO] Phat hien su co khan cap! Ngat ca ban hang ngay lap tuc.\n');
            break;
        }

        if (order_status == 0) {
            printf('[THONG BAO] Don hang nay da bi huy hoac loi nguyen lieu. Bo qua!\n');
            cancelled_orders++;
            continue;
        }

        printf('Nhap gia goc do uong (VNĐ): ');
        scanf('%lf', &base_price);
        printf('Chon Size (1: Size S, 2: Size M (+6000), 3: Size L (+10000)): ');
        scanf('%d', &size_choice);
        printf('Nhap so luong topping (dong gia 8000/topping): ');
        scanf('%d', &topping_count);
        printf('Co the thanh vien Vang khong? (1: Co, 0: Khong): ');
        scanf('%d', &is_gold_member);

        double item_price = base_price;
        if (size_choice == 2) {
            item_price += 6000.0;
        } else if (size_choice == 3) {
            item_price += 10000.0;
        }

        item_price += topping_count * 8000.0;

        if (is_gold_member == 1) {
            item_price = item_price * 0.9;
        }

        total_revenue += item_price;
        completed_orders++;
        printf('-> Thanh tien don hang nay: %.2f VNĐ\n', item_price);
    }

    printf('\n===========================================\n');
    printf('        BAO CAO TONG KET CA BAN HANG         \n');
    printf('===========================================\n');
    printf('Tong so don hoan thanh thanh cong: %d\n', completed_orders);
    printf('Tong so don bi huy / bo qua:       %d\n', cancelled_orders);
    printf('Tong doanh thu thuc te trong ca:    %.2f VNĐ\n', total_revenue);
    printf('===========================================\n');

    return 0;
}