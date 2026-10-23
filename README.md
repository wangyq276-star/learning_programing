# learning_programing

学习 Python / Java / C / C++ 的代码集合。

本仓库用「一个仓库 + 四个代码目录」的方式统一管理分散在不同软件目录下的练习代码，
**原文件夹位置保持不变**（VS Code、PyCharm、IDEA 里的项目都不会失效）。

## 目录

| 仓库中的目录 | 真实位置（原始文件夹，未移动） | 内容 |
| --- | --- | --- |
| `C++Program/` | `D:\VScode\C++Program` | C++ 算法与数据结构练习 |
| `CProgram/` | `D:\VScode\CProgram` | C 语言练习 |
| `IdeaProjects/` | `C:\Users\32051\IdeaProjects` | Java（IntelliJ IDEA 项目） |
| `PythonProject/` | `D:\Python3.13.15AndPycharm\PyCharm 2026.2.3\PythonProject` | Python（PyCharm 项目） |

## 它是怎么工作的

本地的 git 仓库在 `D:\VScode\Git_store`，仓库工作区里的四个目录是指向上述真实位置的
**目录联接（junction，相当于 Windows 的目录快捷方式）**，不是复制品：

- 本地没有第二份代码，磁盘占用不增加；
- 四个原始文件夹的位置、名称都没有改动；
- 在这里 `git add` / `git commit` 收录的就是四个真实目录里的文件内容；
- 在 VS Code / PyCharm / IDEA 里照常写代码，回到 `Git_store` 提交即可。

> 联接是用命令 `cmd /c mklink /J` 创建的，删除联接不会删除真实文件，
> 但**不要**用资源管理器右键删除，也不要在本仓库里执行 `git clean -fdx`
> —— 那会顺着联接删掉四个真实目录里的内容。

## 日常使用

```powershell
cd D:\VScode\Git_store

git status              # 看四个项目里改了什么
git add -A
git commit -m "说明这次改了什么"
git push
```

首次推送后，之后再推送只需 `git add -A; git commit -m "..."; git push`。
