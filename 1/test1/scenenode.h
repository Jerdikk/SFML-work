#ifndef SCENENODE_H
#define SCENENODE_H


class SceneNode
{
    public:

        typedef std::unique_ptr<SceneNode> Ptr;

        SceneNode();
    protected:
    private:
        std::vector<Ptr> mChildren;
        SceneNode*  mParent;
};

#endif // SCENENODE_H
