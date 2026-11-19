# Machine Learning 2022 Spring (李宏毅机器学习2022春)

本仓库为**李宏毅教授（Hung-yi Lee）2022 年春季机器学习课程**的课后作业（Homework）代码与笔记合集。
主要基于 PyTorch 框架实现，涵盖从基础的回归、分类到前沿的生成模型、强化学习、可解释性 AI 等核心领域。
原仓库地址为：https://github.com/virginiakm1988/ML2022-Spring

## 📂 目录结构

```text
ML2022-Spring/
├── HW01_COVID-19/        # 作业1：COVID-19 阳性率预测 (Regression)
├── HW02_Phoneme/         # 作业2：语音音素分类 (Classification)
├── HW03_Food/            # 作业3：食物图像分类 (CNN)
├── HW04_Speaker/         # 作业4：说话人识别 (Self-attention)
├── HW05_Translation/     # 作业5：机器翻译 (Transformer)
├── HW06_GAN/             # 作业6：动漫人脸生成 (GAN)
├── HW07_Anomaly/         # 作业7：异常检测 (Auto-encoder)
├── HW08_Attack/          # 作业8：对抗攻击 (Adversarial Attack)
├── HW09_Adaptation/      # 作业9：领域自适应 (Domain Adaptation)
├── HW10_RL/              # 作业10：强化学习 (Reinforcement Learning)
├── HW11_Transfer/        # 作业11：迁移学习 (Transfer Learning)
├── HW12_LifeLong/        # 作业12：终身学习 (Life-long Learning)
├── HW13_Compression/     # 作业13：模型压缩 (Network Compression)
├── HW14_XAI/             # 作业14：可解释性机器学习 (Explainable AI)
└── HW15_MetaLearning/    # 作业15：元学习 (Meta Learning)
```

---

## 📖 作业简介 (Homework Overview)

每个作业的文件夹内都包含独立的 `README.md`、`curve.ipynb`（主运行代码）以及预测结果 `pred.csv`。

*   **HW01: COVID-19 Cases Prediction (Regression)**
    *   **任务**：利用历史数据（检测数量、隔离情况等特征）预测 COVID-19 阳性率。
    *   **技术点**：数据预处理、特征选择、回归模型、MSELoss。
*   **HW02: Phoneme Classification (Classification)**
    *   **任务**：从语音信号（MFCC特征）中识别不同的音素。
    *   **技术点**：全连接网络、交叉熵损失、分类评估指标。
*   **HW03: Food Classification (CNN)**
    *   **任务**：识别不同的食物图像（11分类）。
    *   **技术点**：卷积神经网络 (CNN)、数据增强 (Data Augmentation)。
*   **HW04: Speaker Identification (Self-attention)**
    *   **任务**：从音频中识别当前说话者是谁。
    *   **技术点**：自注意力机制 (Self-attention)、Transformer 编码器。
*   **HW05: Machine Translation (Transformer)**
    *   **任务**：中英文机器翻译。
    *   **技术点**：Seq2Seq 模型、Transformer、位置编码。
*   **HW06: Anime Face Generation (GAN)**
    *   **任务**：生成动漫人脸图片。
    *   **技术点**：生成对抗网络 (GAN)、WGAN-GP 等变体。
*   **HW07: Anomaly Detection (Auto-encoder)**
    *   **任务**：识别出不属于训练集类别的异常样本。
    *   **技术点**：自编码器 (Auto-encoder)、异常打分计算。
*   **HW08: Adversarial Attack**
    *   **任务**：对输入图像添加微小扰动，使得模型分类错误。
    *   **技术点**：FGSM、PGD 等对抗攻击算法。
*   **HW09: Domain Adaptation**
    *   **任务**：将源域训练好的模型迁移到无标签的目标域。
    *   **技术点**：领域自适应、特征提取器对齐。
*   **HW10: Reinforcement Learning**
    *   **任务**：在 OpenAI Gym 环境中训练智能体（如 LunarLander）。
    *   **技术点**：Actor-Critic、PPO 等强化学习算法。
*   **HW11: Transfer Learning**
    *   **任务**：利用预训练模型完成新的分类任务。
    *   **技术点**：微调 (Fine-tuning)、特征冻结。
*   **HW12: Life-long Learning**
    *   **任务**：在一个模型上连续学习多个任务，防止灾难性遗忘。
    *   **技术点**：EWC、LwF 等持续学习方法。
*   **HW13: Network Compression**
    *   **任务**：压缩模型大小且尽量保持准确率。
    *   **技术点**：剪枝 (Pruning)、知识蒸馏 (Knowledge Distillation)。
*   **HW14: Explainable AI**
    *   **任务**：解释图像分类模型“为什么”做出这样的判断。
    *   **技术点**：Saliency Map、Integrated Gradients。
*   **HW15: Meta Learning**
    *   **任务**：让模型学会“学习”，在少量样本下快速适应新任务。
    *   **技术点**：MAML、ProtoNet。

---

## ⚙️ 环境依赖
所有作业均在以下环境中测试通过：
*   Python >= 3.8
*   PyTorch >= 1.10 (建议使用 GPU 加速)
*   NumPy / Pandas / Scikit-learn
*   tqdm (进度条)
*   TensorBoard (训练可视化)

安装依赖：
```bash
pip install torch torchvision numpy pandas scikit-learn tqdm tensorboard
```

## 🚀 使用说明
1. 进入对应的作业文件夹（如 `HW01_COVID-19`）。
2. 根据该文件夹下的 `README.md` 下载对应的数据集，放置在正确的路径。
3. 使用 Jupyter Notebook 或 VS Code 打开 `curve.ipynb`。
4. 点击“全部运行”即可开始训练。
5. 训练过程中可开启 TensorBoard 监控 Loss 曲线，最终结果会保存在 `pred.csv` 中。

## ⚠️ 声明
本仓库代码仅供学习与参考交流使用。
