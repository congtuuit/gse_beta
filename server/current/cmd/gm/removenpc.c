#include <ansi.h>

// Lệnh: removenpc <object_id>
// Xóa NPC khỏi bản đồ nếu object id hợp lệ và là NPC (không phải user)
int main(object me, string arg)
{
    object npc;
    if (is_player(me))
    {
        notify("Bạn không có đủ quyền.");
        return 1;
    }
    if (!arg || arg == "")
    {
        notify("Cú pháp: removenpc <object_id>");
        return 1;
    }
    npc = find_any_object(arg);
    if (!objectp(npc))
    {
        notify("Không tìm thấy NPC với object id này.");
        return 1;
    }
    if (npc->is_user())
    {
        notify("Không thể xóa người chơi.");
        return 1;
    }
    if (!npc->is_char())
    {
        notify("Object này không phải NPC.");
        return 1;
    }
    npc->remove_from_scene();
    destruct(npc);
    notify("Đã xóa NPC thành công.");
    return 1;
} 