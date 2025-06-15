// Biến: Danh sách nhiệm vụ
string *Quest = ({
        "Tạo Hóa Đơn",
        "Bổ Tâm Đan",
        "Thuốc Cấp Cứu",
        "Thuốc Hồi Sinh Tim",
        "Thuốc Tái Sinh",

        "Bột Giải Độc",
        "Thuốc Thanh Tâm",
        "Bột Thiên Vương",
});

int sizeof_quest = sizeof(Quest);

// Hàm: Lấy nhiệm vụ
string get_quest( object who ) { return Quest[ random(sizeof_quest) ]; }
