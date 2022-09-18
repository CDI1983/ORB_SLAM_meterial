#include <unistd.h>
#include <sophus/se3.h>
#include <string>
#include <iostream>
#include <fstream>

// need pangolin for plotting trajectory
#include <pangolin/pangolin.h>
using namespace std;

// path to trajectory file
string groundtruth_file = "../../groundtruth.txt";
string estimated_file = "../../estimated.txt";

// start point is red and end point is blue
void DrawTrajectory(vector<Sophus::SE3,
                    Eigen::aligned_allocator<Sophus::SE3>> poses_g,
                    vector<Sophus::SE3,
                    Eigen::aligned_allocator<Sophus::SE3>> poses_e);

// read data
vector<Sophus::SE3, Eigen::aligned_allocator<Sophus::SE3>>
ReadData(string FileName);

// compute error
double ComputerError(vector<Sophus::SE3,
                     Eigen::aligned_allocator<Sophus::SE3>> poses_g,
                     vector<Sophus::SE3,
                     Eigen::aligned_allocator<Sophus::SE3>> poses_e);

int main(int argc, char **argv){
    vector<Sophus::SE3, Eigen::aligned_allocator<Sophus::SE3>> poses_g;
    vector<Sophus::SE3, Eigen::aligned_allocator<Sophus::SE3>> poses_e;
    poses_g=ReadData(groundtruth_file);
    poses_e=ReadData(estimated_file);
    double trajectory_error_RMSE = ComputerError( poses_g, poses_e);
    cout<<"Trajectory_error_RMSE : "<<trajectory_error_RMSE<<endl;
    DrawTrajectory(poses_g, poses_e);
    return 0;
}

vector<Sophus::SE3, Eigen::aligned_allocator<Sophus::SE3>>
ReadData(string FileName){
    vector<Sophus::SE3, Eigen::aligned_allocator<Sophus::SE3>> poses;
    ifstream fin(FileName);
    if (!fin) {
        cerr << FileName << " not found." << endl;
    }
    while (!fin.eof()) {
        string time;
        long double tx, ty, tz, qx, qy, qz, qw;
        fin >> time >> tx >> ty >> tz >> qx >> qy >> qz >> qw;
        Sophus::SE3 p1(Eigen::Quaterniond(qw, qx, qy, qz), Eigen::Vector3d(tx, ty, tz));
        poses.push_back(p1);
    }
    fin.close();
    return poses;
}

double ComputerError(vector<Sophus::SE3,
                     Eigen::aligned_allocator<Sophus::SE3>> poses_g,
                     vector<Sophus::SE3,
                     Eigen::aligned_allocator<Sophus::SE3>> poses_e){
    Eigen::Matrix<double,6,1> T;
    double errors = 0;
    double RMSE = 0;
    int n = poses_g.size();
    for(int i =0; i< n ; i++){
        T = (poses_g[i].inverse()*poses_e[i]).log();
        errors += T.transpose()*T;
    }
    RMSE = sqrt(errors/n);
    return RMSE;
}

void DrawTrajectory(vector<Sophus::SE3,
                    Eigen::aligned_allocator<Sophus::SE3>> poses_g,
                    vector<Sophus::SE3,
                    Eigen::aligned_allocator<Sophus::SE3>> poses_e){
    if (poses_g.empty()||poses_e.empty()) {
        cerr << "groundtruth or estimated is empty!" << endl;
        return;
    }
// create pangolin window and plot the trajectory
    pangolin::CreateWindowAndBind("Trajectory Viewer", 1024, 768);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    pangolin::OpenGlRenderState s_cam(
            pangolin::ProjectionMatrix(1024, 768, 500, 500, 512, 389, 0.1,
                                       1000),
            pangolin::ModelViewLookAt(0, -0.1, -1.8, 0, 0, 0, 0.0, -1.0,
                                      0.0)
    );
    pangolin::View &d_cam = pangolin::CreateDisplay()
            .SetBounds(0.0, 1.0, pangolin::Attach::Pix(175), 1.0, -1024.0f /
                                                                  768.0f)
            .SetHandler(new pangolin::Handler3D(s_cam));

    while (pangolin::ShouldQuit() == false) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        d_cam.Activate(s_cam);
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
        glLineWidth(2);

        for (size_t i = 0; i < poses_g.size() - 1; i++) {
            glColor3f(1 - (float) i / poses_g.size(), 0.0f, (float) i /
                                                            poses_g.size());
            glBegin(GL_LINES);
            auto p1 = poses_g[i], p2 = poses_g[i + 1];
            glVertex3d(p1.translation()[0], p1.translation()[1],
                       p1.translation()[2]);
            glVertex3d(p2.translation()[0], p2.translation()[1],
                       p2.translation()[2]);
            glEnd();
        }

        for (size_t i = 0; i < poses_e.size() - 1; i++) {
            glColor3f(1 - (float) i / poses_e.size(), 0.0f, (float) i /
                                                            poses_e.size());
            glBegin(GL_LINES);
            auto p1 = poses_e[i], p2 = poses_e[i + 1];
            glVertex3d(p1.translation()[0], p1.translation()[1],
                       p1.translation()[2]);
            glVertex3d(p2.translation()[0], p2.translation()[1],
                       p2.translation()[2]);
            glEnd();
        }

        pangolin::FinishFrame();
        usleep(5000); // sleep 5 ms
    }
}

