import os
import sys

def delete_cpp_files(root_folder):
    for dirpath, dirnames, filenames in os.walk(root_folder):
        for filename in filenames:
            if filename.endswith(".cpp"):
                cpp_path = os.path.join(dirpath, filename)
                try:
                    os.remove(cpp_path)
                    print(f"🗑️ Đã xóa: {cpp_path}")
                except Exception as e:
                    print(f"❌ Lỗi khi xóa {cpp_path}: {e}")

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("❌ Cách dùng: python delete_cpp_files.py <folder_path>")
        sys.exit(1)

    folder_path = sys.argv[1]

    if not os.path.isdir(folder_path):
        print(f"❌ Thư mục không tồn tại: {folder_path}")
        sys.exit(1)

    print(f"🔍 Đang quét và xóa tất cả file .cpp trong: {folder_path}")
    delete_cpp_files(folder_path)
    print("✅ Đã hoàn tất xóa tất cả file .cpp.")
