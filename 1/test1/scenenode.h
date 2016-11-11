#ifndef SCENENODE_H
#define SCENENODE_H


class SceneNode : public sf::Transformable, public sf::Drawable,
                  private sf::NonCopyable
{
    public:

        typedef std::unique_ptr<SceneNode> Ptr;

        SceneNode();
        void attachChild (Ptr child);
        Ptr detachChild(const SceneNode& node);
    protected:
    private:

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;

        std::vector<Ptr> mChildren;
        SceneNode*  mParent;
};

#endif // SCENENODE_H
