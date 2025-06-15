// 变量：任务列表
string *Quest = ({
    "Bảo vệ",
    "Cô gái hái hoa",
    "Thái sát tinh",
    "Công tử Tào",
    "Bố trà",
    "Khách trà",
    "Thương nhân trà",
    "Người nghỉ mát",
    "Trưởng thôn Lý Đại Thẩm",
    "Cô gái nông thôn",
    "Chủ cửa hàng cầm đồ",
    "Vệ binh đô thành",
    "Ông Đỗ Lão Điệp",
    "Chủ cửa hàng trang bị",
    "Cậu bé chăn trâu",
    "Đội trưởng Hàn binh",
    "Thiếu tướng Hàn binh",
    "Thống lĩnh Hàn binh",
    "Hàn Phi",
    "Binh sĩ Hàn Quốc",
    "Tổng quan Hàn",
    "Chủ quán rượu",
    "Chủ quán trọ",
    "Vệ binh nhà tù",
    "Bà già",
    "Văn giáo đầu",
    "Lão nông",
    "Lý Vương Phi",
    "Lưu Bố Đầu",
    "Người lữ hành",
    "Miêu Miêu",
    "Cậu bé chăn cừu",
    "Cậu bé nông gia",
    "Cô gái nông gia",
    "Nông dân",
    "Ăn mày",
    "Tiền Lai Phát",
    "Tiều phu",
    "Vệ binh thương nhân",
    "Ông tiên",
    "Vệ sĩ",
    "Vệ binh",
    "Cô Tôn",
    "Thợ rèn",
    "Vương Bố Đầu",
    "Vệ binh Vương phủ",
    "Chủ cửa hàng vũ khí",
    "Võ giáo đầu",
    "Tiểu An Tử",
    "Vệ binh đảo nhỏ",
    "Tiểu Cẩu Nhi",
    "Cô gái nhỏ",
    "Tiểu Hà",
    "Tiểu Quyên",
    "Tiểu Tương",
    "Tiểu Tú",
    "Tiểu Diệp Tử",
    "Tiểu Ngọc Nhi",
    "Trưởng thôn người mới",
    "Cô gái Hoa Hạnh",
    "Chủ cửa hàng sửa chữa",
    "Chủ cửa hàng thuốc",
    "Bác sĩ tình nguyện",
    "Chủ trạm ngựa",
    "Nho sĩ du lịch",
    "Du hiệp Long Thiếu Du",
    "Người đánh cá",
    "Người đánh cá Hà Đầu",
    "Người đánh cá Ngư Đan",
    "Chủ cửa hàng tạp hóa",
    "Người làm việc",
    "Trương Đại Nương",
    "Trương Liệp Hộ",
    "Triệu Đại",
    "Triệu Đại Nương",
    "Triệu Đại Thẩm",
    "Triệu Nhị",
    "Triệu Lão Đầu",
    "Triệu Nhược",
    "Triệu Tam",
    "Triệu Song Nhi",
    "Triệu Tiểu Muội",
    "Triệu Tiểu Song",
    "Triệu Hinh",
    "Triệu Hinh Nhi",
    "Chu Ác Thiếu",
    "Tay sai nhà Chu",
    "Chu Lão Gia Tử",
    "Thương nhân trang sức",
});

int sizeof_quest = sizeof(Quest);

mapping get_quest(object who)
{
        mapping result = ([]);
        object *user;
        int level, i, size;

        level = who->get_level();

        if (random(100) < 10 && arrayp(user = USER_D->get_player()) && (size = sizeof(user)))
        {
                i = random(size);
                if (user[i] && user[i] != who)
                {
                        result["name"] = sprintf("Gửi tin nhắn đến %s(%d)", user[i]->get_name(), user[i]->get_number());
                        result["exp"] = level * 40;
                        return result;
                }
        }

        result["name"] = sprintf("Gửi tin nhắn đến %s", Quest[random(sizeof_quest)]);
        result["exp"] = level * 20;
        return result;
}
