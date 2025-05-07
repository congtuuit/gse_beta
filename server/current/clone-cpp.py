import os
import shutil
import sys

def clone_c_to_cpp(root_folder):
    for dirpath, dirnames, filenames in os.walk(root_folder):
        for filename in filenames:
            if filename.endswith(".c"):
                c_path = os.path.join(dirpath, filename)
                cpp_path = os.path.join(dirpath, filename[:-2] + ".cpp")

                if not os.path.exists(cpp_path):
                    shutil.copy2(c_path, cpp_path)
                    print(f"✅ Cloned: {c_path} → {cpp_path}")
                else:
                    print(f"⚠️ Skipped (already exists): {cpp_path}")

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("❌ Cách dùng: python clone_c_to_cpp.py <folder_path>")
        sys.exit(1)

    folder_path = sys.argv[1]

    if not os.path.isdir(folder_path):
        print(f"❌ Thư mục không tồn tại: {folder_path}")
        sys.exit(1)

    print(f"🔍 Đang quét thư mục: {folder_path}")
    clone_c_to_cpp(folder_path)
    print("✅ Hoàn tất clone tất cả file .c → .cpp.")
